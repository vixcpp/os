/**
 *
 *  @file IsAdmin.hpp
 *  @author Gaspard Kirira
 *
 *  Vix.cpp
 */
#ifndef VIX_OS_ISADMIN_HPP
#define VIX_OS_ISADMIN_HPP

#include <vix/os/OsResult.hpp>

namespace vix::os
{

  /**
   * @brief Check if the current user has administrative privileges.
   */
  [[nodiscard]] BoolResult is_admin();

} // namespace vix::os

#endif // VIX_OS_ISADMIN_HPP
