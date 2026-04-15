/**
 *
 *  @file UserInfo.hpp
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
#ifndef VIX_OS_USERINFO_HPP
#define VIX_OS_USERINFO_HPP

#include <string>

namespace vix::os
{

  /**
   * @struct UserInfo
   * @brief Information about the current user.
   */
  struct UserInfo
  {
    std::string username; // user login name
    std::string home_dir; // home directory path
    std::string shell;    // default shell (if available)
  };

} // namespace vix::os

#endif // VIX_OS_USERINFO_HPP
