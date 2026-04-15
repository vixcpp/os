/**
 *
 *  @file Sleep.cpp
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

#include <chrono>
#include <thread>

#include <vix/os/Sleep.hpp>

namespace vix::os
{

  void sleep_for_ms(std::uint64_t milliseconds)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
  }

  void sleep_for_seconds(std::uint64_t seconds)
  {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
  }

} // namespace vix::os
