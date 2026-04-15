/**
 *
 *  @file platform_test.cpp
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

#include <cstdlib>
#include <iostream>
#include <string>

#include <vix/os/Platform.hpp>

namespace
{
  void assert_true(bool condition, const std::string &message)
  {
    if (!condition)
    {
      std::cerr << "Assertion failed: " << message << '\n';
      std::exit(1);
    }
  }

  bool is_known_platform(const std::string &value)
  {
    return value == "linux" ||
           value == "windows" ||
           value == "macos" ||
           value == "freebsd" ||
           value == "unknown";
  }

  void test_platform_returns_known_value()
  {
    auto result = vix::os::platform();
    assert_true(result.ok(), "platform() should succeed");
    assert_true(!result.value().empty(), "platform should not be empty");
    assert_true(is_known_platform(result.value()), "platform should be recognized");
  }
} // namespace

int main()
{
  test_platform_returns_known_value();

  std::cout << "vix_os_platform_test passed\n";
  return 0;
}
