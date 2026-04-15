/**
 *
 *  @file PageSize.cpp
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

#include <cstddef>

#include <vix/os/OsError.hpp>
#include <vix/os/PageSize.hpp>

#if defined(_WIN32)
#include <windows.h>
#else
#include <unistd.h>
#endif

namespace vix::os
{

  SizeResult page_size()
  {
#if defined(_WIN32)
    SYSTEM_INFO info{};
    GetSystemInfo(&info);

    if (info.dwPageSize == 0)
    {
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "failed to query page size");
    }

    return static_cast<std::size_t>(info.dwPageSize);
#else
    const long value = ::sysconf(_SC_PAGESIZE);
    if (value <= 0)
    {
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "failed to query page size");
    }

    return static_cast<std::size_t>(value);
#endif
  }

} // namespace vix::os
