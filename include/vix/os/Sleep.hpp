/**
 *
 *  @file Sleep.hpp
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
#ifndef VIX_OS_SLEEP_HPP
#define VIX_OS_SLEEP_HPP

#include <cstdint>

namespace vix::os
{

  /**
   * @brief Sleep for the given number of milliseconds.
   */
  void sleep_for_ms(std::uint64_t milliseconds);

  /**
   * @brief Sleep for the given number of seconds.
   */
  void sleep_for_seconds(std::uint64_t seconds);

} // namespace vix::os

#endif // VIX_OS_SLEEP_HPP
