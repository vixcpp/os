/**
 *
 *  @file OsResult.hpp
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
#ifndef VIX_OS_OSRESULT_HPP
#define VIX_OS_OSRESULT_HPP

#include <string>

#include <vix/error/Result.hpp>

namespace vix::os
{

  /**
   * @brief Generic OS result types.
   */

  using StringResult = vix::error::Result<std::string>;
  using BoolResult = vix::error::Result<bool>;
  using IntResult = vix::error::Result<int>;
  using UIntResult = vix::error::Result<unsigned int>;
  using SizeResult = vix::error::Result<std::size_t>;

} // namespace vix::os

#endif // VIX_OS_OSRESULT_HPP
