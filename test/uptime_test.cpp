/**
 *
 *  @file uptime_test.cpp
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
#include <cstdint>

#include <vix/error/ErrorCode.hpp>
#include <vix/os/Uptime.hpp>

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

  void test_uptime_returns_value_or_supported_error()
  {
    auto result = vix::os::uptime();

    if (result.ok())
    {
      assert_true(result.value() >= static_cast<std::uint64_t>(0),
                  "uptime should be non-negative");
      return;
    }

    const auto &error = result.error();
    assert_true(
        error.code() == vix::error::ErrorCode::NotSupported ||
            error.code() == vix::error::ErrorCode::ExternalError,
        "uptime should fail only with a supported OS-related error");
  }
} // namespace

int main()
{
  test_uptime_returns_value_or_supported_error();

  std::cout << "vix_os_uptime_test passed\n";
  return 0;
}
