/**
 *
 *  @file Uptime.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.
 *  All rights reserved.
 *  https://github.com/vixcpp/vix
 *
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 */

#include <cstdint>
#include <fstream>
#include <string>

#include <vix/os/OsError.hpp>
#include <vix/os/Uptime.hpp>

#if defined(_WIN32)
#include <windows.h>
#elif defined(__APPLE__)
#include <sys/sysctl.h>
#include <sys/time.h>
#include <time.h>
#else
#include <time.h>
#endif

namespace vix::os
{

  vix::error::Result<std::uint64_t> uptime()
  {
#if defined(_WIN32)
    const ULONGLONG ms = GetTickCount64();
    return static_cast<std::uint64_t>(ms / 1000ULL);

#elif defined(__linux__)
    std::ifstream input("/proc/uptime");
    if (!input.is_open())
    {
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "failed to read /proc/uptime");
    }

    double seconds = 0.0;
    input >> seconds;

    if (!input.good() && !input.eof())
    {
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "failed to parse /proc/uptime");
    }

    if (seconds < 0.0)
    {
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "invalid uptime value");
    }

    return static_cast<std::uint64_t>(seconds);

#elif defined(__APPLE__)
    struct timeval boot_time{};
    std::size_t size = sizeof(boot_time);
    int mib[2] = {CTL_KERN, KERN_BOOTTIME};

    if (sysctl(mib, 2, &boot_time, &size, nullptr, 0) != 0)
    {
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "failed to query boot time");
    }

    const std::time_t now = std::time(nullptr);
    if (now < 0 || boot_time.tv_sec <= 0 || now < boot_time.tv_sec)
    {
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "failed to compute uptime");
    }

    return static_cast<std::uint64_t>(now - boot_time.tv_sec);

#else
    return make_os_error(
        OsErrorCode::Unsupported,
        "uptime is not supported on this platform");
#endif
  }

} // namespace vix::os
