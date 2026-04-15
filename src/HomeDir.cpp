/**
 *
 *  @file HomeDir.cpp
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

#include <vix/os/HomeDir.hpp>
#include <vix/os/OsError.hpp>

#if defined(_WIN32)
#include <windows.h>
#else
#include <unistd.h>
#include <pwd.h>
#endif

namespace vix::os
{

  StringResult home_dir()
  {
#if defined(_WIN32)
    if (const char *value = std::getenv("USERPROFILE"))
    {
      return std::string(value);
    }

    const char *drive = std::getenv("HOMEDRIVE");
    const char *path = std::getenv("HOMEPATH");

    if (drive && path)
    {
      return std::string(drive) + std::string(path);
    }

    return make_os_error(
        OsErrorCode::NotFound,
        "failed to resolve home directory");

#else
    if (const char *value = std::getenv("HOME"))
    {
      return std::string(value);
    }

    struct passwd *pw = getpwuid(getuid());
    if (pw && pw->pw_dir)
    {
      return std::string(pw->pw_dir);
    }

    return make_os_error(
        OsErrorCode::NotFound,
        "failed to resolve home directory");
#endif
  }

} // namespace vix::os
