/**
 *
 *  @file CurrentUser.cpp
 *  @author Gaspard Kirira
 *
 *  Vix.cpp
 */

#include <cstdlib>
#include <string>

#include <vix/os/CurrentUser.hpp>
#include <vix/os/OsError.hpp>

#if defined(_WIN32)
#include <windows.h>
#else
#include <unistd.h>
#include <pwd.h>
#endif

namespace vix::os
{

  vix::error::Result<UserInfo> current_user()
  {
    UserInfo info{};

#if defined(_WIN32)
    char username[256];
    DWORD size = sizeof(username);

    if (!GetUserNameA(username, &size))
    {
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "failed to get username");
    }

    info.username = username;

    const char *home = std::getenv("USERPROFILE");
    if (home)
      info.home_dir = home;

    const char *shell = std::getenv("COMSPEC");
    if (shell)
      info.shell = shell;

#else
    struct passwd *pw = getpwuid(getuid());
    if (!pw)
    {
      return make_os_error(
          OsErrorCode::SystemCallFailed,
          "failed to get user info");
    }

    info.username = pw->pw_name ? pw->pw_name : "";
    info.home_dir = pw->pw_dir ? pw->pw_dir : "";
    info.shell = pw->pw_shell ? pw->pw_shell : "";
#endif

    return info;
  }

} // namespace vix::os
