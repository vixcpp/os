/**
 *
 *  @file Arch.cpp
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

#include <string>

#include <vix/os/Arch.hpp>

namespace vix::os
{

  StringResult arch()
  {
#if defined(__x86_64__) || defined(_M_X64)
    return std::string("x86_64");
#elif defined(__i386__) || defined(_M_IX86)
    return std::string("x86");
#elif defined(__aarch64__) || defined(_M_ARM64)
    return std::string("arm64");
#elif defined(__arm__) || defined(_M_ARM)
    return std::string("arm");
#elif defined(__riscv) && (__riscv_xlen == 64)
    return std::string("riscv64");
#elif defined(__riscv) && (__riscv_xlen == 32)
    return std::string("riscv32");
#else
    return std::string("unknown");
#endif
  }

} // namespace vix::os
