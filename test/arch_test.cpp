/**
 *
 *  @file arch_test.cpp
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

#include <vix/os/Arch.hpp>

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

  bool is_known_arch(const std::string &value)
  {
    return value == "x86_64" ||
           value == "x86" ||
           value == "arm64" ||
           value == "arm" ||
           value == "riscv64" ||
           value == "riscv32" ||
           value == "unknown";
  }

  void test_arch_returns_known_value()
  {
    auto result = vix::os::arch();
    assert_true(result.ok(), "arch() should succeed");
    assert_true(!result.value().empty(), "arch should not be empty");
    assert_true(is_known_arch(result.value()), "arch should be recognized");
  }
} // namespace

int main()
{
  test_arch_returns_known_value();

  std::cout << "vix_os_arch_test passed\n";
  return 0;
}
