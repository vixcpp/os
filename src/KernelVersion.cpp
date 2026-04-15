/**
 *
 *  @file KernelVersion.cpp
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

#include <string>

#include <vix/os/OsError.hpp>
#include <vix/os/KernelVersion.hpp>

#if defined(_WIN32)
#include <windows.h>
#elif defined(__unix__) || defined(__APPLE__)
#include <sys/utsname.h>
#endif

namespace vix::os
{

  StringResult kernel_version()
  {
#if defined(_WIN32)
    OSVERSIONINFOEXW info{};
    info.dwOSVersionInfoSize = sizeof(info);

#pragma warning(push)
#pragma warning(disable : 4996)
    if (!GetVersionExW(reinterpret_cast<OSVERSIONINFOW *>(&info)))
    {
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "failed to query Windows version");
    }
#pragma warning(pop)

    return std::to_string(info.dwMajorVersion) + "." +
           std::to_string(info.dwMinorVersion) + "." +
           std::to_string(info.dwBuildNumber);

#elif defined(__unix__) || defined(__APPLE__)
    struct utsname info{};

    if (uname(&info) != 0)
    {
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "failed to query kernel version");
    }

    return std::string(info.release);
#else
    return make_os_error(
        OsErrorCode::Unsupported,
        "kernel version is not supported on this platform");
#endif
  }

} // namespace vix::os
