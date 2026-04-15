/**
 *
 *  @file kernel_version_test.cpp
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

#include <vix/os/KernelVersion.hpp>

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

  void test_kernel_version_returns_value_or_supported_error()
  {
    auto result = vix::os::kernel_version();

    if (result.ok())
    {
      assert_true(!result.value().empty(), "kernel_version should not be empty on success");
      return;
    }

    const auto &error = result.error();
    assert_true(
        error.code() == vix::error::ErrorCode::NotSupported ||
            error.code() == vix::error::ErrorCode::ExternalError,
        "kernel_version should fail only with a supported OS-related error");
  }
} // namespace

int main()
{
  test_kernel_version_returns_value_or_supported_error();

  std::cout << "vix_os_kernel_version_test passed\n";
  return 0;
}
