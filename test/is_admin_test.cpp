/**
 *
 *  @file is_admin_test.cpp
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

#include <vix/os/IsAdmin.hpp>

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

  void test_is_admin_returns_boolean()
  {
    auto result = vix::os::is_admin();
    assert_true(result.ok(), "is_admin() should succeed");

    const bool value = result.value();
    assert_true(value == true || value == false, "is_admin should return a boolean");
  }
} // namespace

int main()
{
  test_is_admin_returns_boolean();

  std::cout << "vix_os_is_admin_test passed\n";
  return 0;
}
