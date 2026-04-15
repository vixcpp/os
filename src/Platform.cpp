/**
 *
 *  @file Platform.cpp
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

#include <vix/os/Platform.hpp>

namespace vix::os
{

  StringResult platform()
  {
#if defined(_WIN32)
    return std::string("windows");
#elif defined(__APPLE__) && defined(__MACH__)
    return std::string("macos");
#elif defined(__linux__)
    return std::string("linux");
#elif defined(__FreeBSD__)
    return std::string("freebsd");
#else
    return std::string("unknown");
#endif
  }

} // namespace vix::os
