/**
 *
 *  @file page_size_test.cpp
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

#include <vix/os/PageSize.hpp>

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

  void test_page_size_returns_positive_value()
  {
    auto result = vix::os::page_size();
    assert_true(result.ok(), "page_size() should succeed");
    assert_true(result.value() > 0, "page size should be greater than 0");
  }
} // namespace

int main()
{
  test_page_size_returns_positive_value();

  std::cout << "vix_os_page_size_test passed\n";
  return 0;
}
