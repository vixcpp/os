/**
 *
 *  @file cpu_count_test.cpp
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

#include <vix/os/CpuCount.hpp>

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

  void test_cpu_count_returns_positive_value()
  {
    auto result = vix::os::cpu_count();
    assert_true(result.ok(), "cpu_count() should succeed");
    assert_true(result.value() > 0, "cpu count should be greater than 0");
  }
} // namespace

int main()
{
  test_cpu_count_returns_positive_value();

  std::cout << "vix_os_cpu_count_test passed\n";
  return 0;
}
