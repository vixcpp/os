/**
 *
 *  @file CurrentPid.cpp
 *  @author Gaspard Kirira
 *
 *  Vix.cpp
 */

#include <vix/os/CurrentPid.hpp>

#if defined(_WIN32)
#include <windows.h>
#else
#include <unistd.h>
#endif

namespace vix::os
{

  IntResult current_pid()
  {
#if defined(_WIN32)
    return static_cast<int>(GetCurrentProcessId());
#else
    return static_cast<int>(getpid());
#endif
  }

} // namespace vix::os
