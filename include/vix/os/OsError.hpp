/**
 *
 *  @file OsError.hpp
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
#ifndef VIX_OS_OSERROR_HPP
#define VIX_OS_OSERROR_HPP

#include <string>

#include <vix/error/Error.hpp>
#include <vix/error/ErrorCategory.hpp>
#include <vix/error/ErrorCode.hpp>

namespace vix::os
{

  /**
   * @enum OsErrorCode
   * @brief OS-specific semantic error codes.
   */
  enum class OsErrorCode
  {
    None = 0,
    Unsupported,
    SystemCallFailed,
    PermissionDenied,
    NotFound,
    InvalidArgument,
    Unknown
  };

  /**
   * @brief OS error category.
   */
  [[nodiscard]] inline constexpr vix::error::ErrorCategory os_error_category() noexcept
  {
    return vix::error::ErrorCategory("os");
  }

  /**
   * @brief Convert OsErrorCode to generic ErrorCode.
   */
  [[nodiscard]] inline constexpr vix::error::ErrorCode to_error_code(OsErrorCode code) noexcept
  {
    using vix::error::ErrorCode;

    switch (code)
    {
    case OsErrorCode::None:
      return ErrorCode::Ok;
    case OsErrorCode::Unsupported:
      return ErrorCode::NotSupported;
    case OsErrorCode::SystemCallFailed:
      return ErrorCode::ExternalError;
    case OsErrorCode::PermissionDenied:
      return ErrorCode::PermissionDenied;
    case OsErrorCode::NotFound:
      return ErrorCode::NotFound;
    case OsErrorCode::InvalidArgument:
      return ErrorCode::InvalidArgument;
    case OsErrorCode::Unknown:
      return ErrorCode::Unknown;
    }

    return ErrorCode::Unknown;
  }

  /**
   * @brief Convert OsErrorCode to string.
   */
  [[nodiscard]] inline const char *to_string(OsErrorCode code) noexcept
  {
    switch (code)
    {
    case OsErrorCode::None:
      return "none";
    case OsErrorCode::Unsupported:
      return "unsupported";
    case OsErrorCode::SystemCallFailed:
      return "system_call_failed";
    case OsErrorCode::PermissionDenied:
      return "permission_denied";
    case OsErrorCode::NotFound:
      return "not_found";
    case OsErrorCode::InvalidArgument:
      return "invalid_argument";
    case OsErrorCode::Unknown:
      return "unknown";
    }

    return "unknown";
  }

  /**
   * @brief Create a structured OS error.
   */
  [[nodiscard]] inline vix::error::Error make_os_error(OsErrorCode code, std::string message)
  {
    return vix::error::Error(
        to_error_code(code),
        os_error_category(),
        std::move(message));
  }

} // namespace vix::os

#endif // VIX_OS_OSERROR_HPP
