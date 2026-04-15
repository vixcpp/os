/**
 *
 *  @file CurrentPid.hpp
 *  @author Gaspard Kirira
 *
 *  Vix.cpp
 */
#ifndef VIX_OS_CURRENTPID_HPP
#define VIX_OS_CURRENTPID_HPP

#include <vix/os/OsResult.hpp>

namespace vix::os
{

  /**
   * @brief Get current process ID.
   */
  [[nodiscard]] IntResult current_pid();

} // namespace vix::os

#endif // VIX_OS_CURRENTPID_HPP
