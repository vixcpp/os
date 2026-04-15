/**
 *
 *  @file OsInfo.hpp
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
#ifndef VIX_OS_OSINFO_HPP
#define VIX_OS_OSINFO_HPP

#include <string>

namespace vix::os
{

  /**
   * @struct OsInfo
   * @brief Basic information about the operating system.
   */
  struct OsInfo
  {
    std::string platform;       // linux, windows, macos
    std::string architecture;   // x86_64, arm64, etc.
    std::string kernel_version; // kernel / OS version
    std::string hostname;       // machine hostname
  };

} // namespace vix::os

#endif // VIX_OS_OSINFO_HPP
