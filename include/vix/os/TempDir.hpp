/**
 *
 *  @file TempDir.hpp
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
#ifndef VIX_OS_TEMPDIR_HPP
#define VIX_OS_TEMPDIR_HPP

#include <vix/os/OsResult.hpp>

namespace vix::os
{

  /**
   * @brief Return the system temporary directory.
   */
  [[nodiscard]] StringResult temp_dir();

} // namespace vix::os

#endif // VIX_OS_TEMPDIR_HPP
