/**
 *
 *  @file CurrentUser.hpp
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
#ifndef VIX_OS_CURRENTUSER_HPP
#define VIX_OS_CURRENTUSER_HPP

#include <vix/os/OsResult.hpp>
#include <vix/os/UserInfo.hpp>

namespace vix::os
{

  /**
   * @brief Get information about the current user.
   */
  [[nodiscard]] vix::error::Result<UserInfo> current_user();

} // namespace vix::os

#endif // VIX_OS_CURRENTUSER_HPP
