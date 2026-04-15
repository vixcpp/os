/**
 *
 *  @file CpuInfo.hpp
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
#ifndef VIX_OS_CPUINFO_HPP
#define VIX_OS_CPUINFO_HPP

#include <string>
#include <cstdint>

namespace vix::os
{

  /**
   * @struct CpuInfo
   * @brief Basic CPU information.
   */
  struct CpuInfo
  {
    std::string model;        // CPU model name (if available)
    std::uint32_t cores{0};   // number of logical cores
    std::uint32_t threads{0}; // number of threads (if different)
  };

} // namespace vix::os

#endif // VIX_OS_CPUINFO_HPP
