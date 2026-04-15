/**
 *
 *  @file Hostname.hpp
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
#ifndef VIX_OS_HOSTNAME_HPP
#define VIX_OS_HOSTNAME_HPP

#include <vix/os/OsResult.hpp>

namespace vix::os
{

  /**
   * @brief Return the current machine hostname.
   */
  [[nodiscard]] StringResult hostname();

} // namespace vix::os

#endif // VIX_OS_HOSTNAME_HPP
