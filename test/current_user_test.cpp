/**
 *
 *  @file current_user_test.cpp
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

#include <vix/os/CurrentUser.hpp>

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

  void test_current_user_returns_basic_info()
  {
    auto result = vix::os::current_user();
    assert_true(result.ok(), "current_user() should succeed");

    const auto &user = result.value();

    assert_true(!user.username.empty(), "username should not be empty");
    assert_true(!user.home_dir.empty(), "home_dir should not be empty");
  }
} // namespace

int main()
{
  test_current_user_returns_basic_info();

  std::cout << "vix_os_current_user_test passed\n";
  return 0;
}
