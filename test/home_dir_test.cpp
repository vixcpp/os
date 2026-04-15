/**
 *
 *  @file home_dir_test.cpp
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

#include <vix/os/HomeDir.hpp>

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

  void test_home_dir_returns_value()
  {
    auto result = vix::os::home_dir();
    assert_true(result.ok(), "home_dir() should succeed");
    assert_true(!result.value().empty(), "home_dir should not be empty");
  }
} // namespace

int main()
{
  test_home_dir_returns_value();

  std::cout << "vix_os_home_dir_test passed\n";
  return 0;
}
