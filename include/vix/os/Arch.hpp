/**
 *
 *  @file Arch.hpp
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
#ifndef VIX_OS_ARCH_HPP
#define VIX_OS_ARCH_HPP

#include <vix/os/OsResult.hpp>

namespace vix::os
{

  /**
   * @brief Return the current CPU architecture name.
   *
   * Typical values:
   * - x86_64
   * - x86
   * - arm64
   * - arm
   * - riscv64
   * - unknown
   */
  [[nodiscard]] StringResult arch();

} // namespace vix::os

#endif // VIX_OS_ARCH_HPP
