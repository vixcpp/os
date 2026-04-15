/**
 *
 *  @file Platform.hpp
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
#ifndef VIX_OS_PLATFORM_HPP
#define VIX_OS_PLATFORM_HPP

#include <vix/os/OsResult.hpp>

namespace vix::os
{

  /**
   * @brief Return the current platform name.
   *
   * Typical values:
   * - linux
   * - windows
   * - macos
   * - freebsd
   * - unknown
   */
  [[nodiscard]] StringResult platform();

} // namespace vix::os

#endif // VIX_OS_PLATFORM_HPP
