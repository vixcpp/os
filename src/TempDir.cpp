/**
 *
 *  @file TempDir.cpp
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

#include <cstdlib>
#include <string>

#include <vix/os/OsError.hpp>
#include <vix/os/TempDir.hpp>

#if defined(_WIN32)
#include <windows.h>
#endif

namespace vix::os
{

  StringResult temp_dir()
  {
#if defined(_WIN32)
    char buffer[MAX_PATH + 1]{};
    const DWORD length = GetTempPathA(MAX_PATH, buffer);

    if (length == 0 || length > MAX_PATH)
    {
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "failed to resolve temp directory");
    }

    return std::string(buffer, length);

#else
    if (const char *value = std::getenv("TMPDIR"))
    {
      return std::string(value);
    }

    if (const char *value = std::getenv("TEMP"))
    {
      return std::string(value);
    }

    if (const char *value = std::getenv("TMP"))
    {
      return std::string(value);
    }

    return std::string("/tmp");
#endif
  }

} // namespace vix::os
