/**
 *
 *  @file sleep_test.cpp
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

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>

#include <vix/os/Sleep.hpp>

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

  void test_sleep_for_ms_waits_approximately()
  {
    const auto start = std::chrono::steady_clock::now();
    vix::os::sleep_for_ms(50);
    const auto end = std::chrono::steady_clock::now();

    const auto elapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    assert_true(elapsed >= 40, "sleep_for_ms should wait approximately long enough");
  }

  void test_sleep_for_seconds_waits_approximately()
  {
    const auto start = std::chrono::steady_clock::now();
    vix::os::sleep_for_seconds(1);
    const auto end = std::chrono::steady_clock::now();

    const auto elapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    assert_true(elapsed >= 900, "sleep_for_seconds should wait approximately long enough");
  }
} // namespace

int main()
{
  test_sleep_for_ms_waits_approximately();
  test_sleep_for_seconds_waits_approximately();

  std::cout << "vix_os_sleep_test passed\n";
  return 0;
}
