/**
 *
 *  @file MemoryInfo.hpp
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
#ifndef VIX_OS_MEMORYINFO_HPP
#define VIX_OS_MEMORYINFO_HPP

#include <cstdint>

namespace vix::os
{

  /**
   * @struct MemoryInfo
   * @brief Basic system memory information.
   */
  struct MemoryInfo
  {
    std::uint64_t total_bytes{0};     // total physical memory
    std::uint64_t available_bytes{0}; // available memory
  };

} // namespace vix::os

#endif // VIX_OS_MEMORYINFO_HPP
