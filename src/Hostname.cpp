/**
 *
 *  @file Hostname.cpp
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

#include <array>
#include <string>

#include <vix/os/Hostname.hpp>
#include <vix/os/OsError.hpp>

#if defined(_WIN32)
#include <windows.h>
#else
#include <unistd.h>
#endif

namespace vix::os
{

  StringResult hostname()
  {
#if defined(_WIN32)
    std::array<char, 256> buffer{};
    DWORD size = static_cast<DWORD>(buffer.size());

    if (!GetComputerNameA(buffer.data(), &size))
    {
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "failed to query hostname");
    }

    return std::string(buffer.data(), size);
#else
    std::array<char, 256> buffer{};

    if (gethostname(buffer.data(), buffer.size()) != 0)
    {
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "failed to query hostname");
    }

    buffer.back() = '\0';
    return std::string(buffer.data());
#endif
  }

} // namespace vix::os
