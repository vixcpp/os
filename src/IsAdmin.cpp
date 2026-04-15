/**
 *
 *  @file IsAdmin.cpp
 *  @author Gaspard Kirira
 *
 *  Vix.cpp
 */

#include <vix/os/IsAdmin.hpp>
#include <vix/os/OsError.hpp>

#if defined(_WIN32)
#include <windows.h>
#else
#include <unistd.h>
#endif

namespace vix::os
{

  BoolResult is_admin()
  {
#if defined(_WIN32)
    BOOL isAdmin = FALSE;

    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
    PSID AdministratorsGroup = nullptr;

    if (!AllocateAndInitializeSid(
            &NtAuthority,
            2,
            SECURITY_BUILTIN_DOMAIN_RID,
            DOMAIN_ALIAS_RID_ADMINS,
            0, 0, 0, 0, 0, 0,
            &AdministratorsGroup))
    {
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "failed to initialize SID");
    }

    if (!CheckTokenMembership(nullptr, AdministratorsGroup, &isAdmin))
    {
      FreeSid(AdministratorsGroup);
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "failed to check admin membership");
    }

    FreeSid(AdministratorsGroup);
    return isAdmin == TRUE;

#else
    return geteuid() == 0;
#endif
  }

} // namespace vix::os
