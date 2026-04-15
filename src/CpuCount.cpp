/**
 *
 *  @file CpuCount.cpp
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

#include <thread>

#include <vix/os/CpuCount.hpp>
#include <vix/os/OsError.hpp>

namespace vix::os
{

  UIntResult cpu_count()
  {
    const unsigned int count = std::thread::hardware_concurrency();
    if (count == 0)
    {
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "failed to query cpu count");
    }

    return count;
  }

} // namespace vix::os
