/**
 *
 *  @file Uptime.hpp
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
#ifndef VIX_OS_UPTIME_HPP
#define VIX_OS_UPTIME_HPP

#include <cstdint>

#include <vix/error/Result.hpp>

namespace vix::os
{

  /**
   * @brief Return system uptime in seconds.
   */
  [[nodiscard]] vix::error::Result<std::uint64_t> uptime();

} // namespace vix::os

#endif // VIX_OS_UPTIME_HPP
