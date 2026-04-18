#  @file CMakeLists.txt
#  @author Gaspard Kirira
#
#  Copyright 2025, Gaspard Kirira. All rights reserved.
#  https://github.com/vixcpp/vix
#  Use of this source code is governed by a MIT license
#  that can be found in the License file.
#
# ====================================================================
# Vix.cpp - Os Module
# ====================================================================
# Purpose:
#   Cross-platform operating system utilities for Vix.
#   Provides high-level APIs for platform detection, user/process info,
#   system directories, cpu/memory-related helpers, and small OS helpers.
#
#   Builds as STATIC when sources exist, otherwise as a header-only
#   INTERFACE target.
#
# Public Targets:
#   - vix_os  : The actual library target (STATIC or INTERFACE)
#   - vix::os : Namespaced alias for consumers
#
# Public Dependencies:
#   - vix::error
#   - vix::path
#
# Installation/Export:
#   - Umbrella build exports into: VixTargets
#   - Standalone build exports into: vix_osTargets
# ====================================================================

cmake_minimum_required(VERSION 3.20)
project(vix_os VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# --------------------------------------------------------------------
# Global settings
# --------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# --------------------------------------------------------------------
# Export set selection
# --------------------------------------------------------------------
if (DEFINED VIX_UMBRELLA_BUILD AND VIX_UMBRELLA_BUILD)
  set(VIX_OS_EXPORT_SET VixTargets)
else()
  set(VIX_OS_EXPORT_SET vix_osTargets)
endif()

# --------------------------------------------------------------------
# Umbrella build policy:
# When building inside the Vix umbrella, dependencies are managed by the
# umbrella (add_subdirectory order + options). Os must not FetchContent
# nor add sibling subdirectories in umbrella mode.
# --------------------------------------------------------------------
if (DEFINED VIX_UMBRELLA_BUILD AND VIX_UMBRELLA_BUILD)
  set(VIX_OS_FETCH_ERROR OFF CACHE BOOL "Auto-fetch vix::error if missing" FORCE)
  set(VIX_OS_FETCH_PATH  OFF CACHE BOOL "Auto-fetch vix::path if missing" FORCE)
endif()

# --------------------------------------------------------------------
# Sources discovery
# --------------------------------------------------------------------
file(GLOB_RECURSE OS_SOURCES CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# --------------------------------------------------------------------
# Dependencies
# --------------------------------------------------------------------
option(VIX_OS_FETCH_ERROR "Auto-fetch vix::error if missing" ON)
option(VIX_OS_FETCH_PATH  "Auto-fetch vix::path if missing" ON)

if (DEFINED VIX_UMBRELLA_BUILD AND VIX_UMBRELLA_BUILD)
  if (NOT TARGET vix::error)
    message(FATAL_ERROR "[os] Umbrella build: vix::error must be provided by umbrella before os.")
  endif()

  if (NOT TARGET vix::path)
    message(FATAL_ERROR "[os] Umbrella build: vix::path must be provided by umbrella before os.")
  endif()
else()
  if (NOT TARGET vix::error)
    if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/../error/CMakeLists.txt")
      message(STATUS "[os] Adding error from sibling: ../error")
      add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../error" "error")
    else()
      find_package(vix_error CONFIG QUIET)
    endif()

    if (NOT TARGET vix::error)
      if (VIX_OS_FETCH_ERROR)
        include(FetchContent)
        message(STATUS "[os] Fetching vix::error via FetchContent")
        FetchContent_Declare(vix_error
          GIT_REPOSITORY https://github.com/vixcpp/error.git
          GIT_TAG        v0.1.0
        )
        FetchContent_MakeAvailable(vix_error)
      else()
        message(FATAL_ERROR
          "vix::error not found. Enable VIX_OS_FETCH_ERROR=ON, install vix_error, or provide the target before os."
        )
      endif()
    endif()
  endif()

  if (NOT TARGET vix::path)
    if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/../path/CMakeLists.txt")
      message(STATUS "[os] Adding path from sibling: ../path")
      add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../path" "path")
    else()
      find_package(vix_path CONFIG QUIET)
    endif()

    if (NOT TARGET vix::path)
      if (VIX_OS_FETCH_PATH)
        include(FetchContent)
        message(STATUS "[os] Fetching vix::path via FetchContent")
        FetchContent_Declare(vix_path
          GIT_REPOSITORY https://github.com/vixcpp/path.git
          GIT_TAG        v0.1.0
        )
        FetchContent_MakeAvailable(vix_path)
      else()
        message(FATAL_ERROR
          "vix::path not found. Enable VIX_OS_FETCH_PATH=ON, install vix_path, or provide the target before os."
        )
      endif()
    endif()
  endif()
endif()

set(VIX_ERROR_TARGET vix::error)
set(VIX_PATH_TARGET  vix::path)

# --------------------------------------------------------------------
# Library target
# --------------------------------------------------------------------
if (OS_SOURCES)
  message(STATUS "[os] Building STATIC library with detected sources.")

  add_library(vix_os STATIC ${OS_SOURCES})
  add_library(vix::os ALIAS vix_os)

  target_compile_features(vix_os PUBLIC cxx_std_20)

  target_include_directories(vix_os
    PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )

  target_link_libraries(vix_os
    PUBLIC
      ${VIX_ERROR_TARGET}
      ${VIX_PATH_TARGET}
  )

  # Build-only helpers must not leak into exported interfaces.
if (NOT MSVC)
  target_compile_options(vix_os PRIVATE
    -Wall
    -Wextra
    -Wpedantic
  )
endif()

if (VIX_ENABLE_SANITIZERS AND NOT MSVC)
  target_compile_options(vix_os PRIVATE
    -fno-omit-frame-pointer
    -fsanitize=address,undefined
  )
  target_link_options(vix_os PRIVATE
    -fsanitize=address,undefined
  )
endif()

  set_target_properties(vix_os PROPERTIES
    OUTPUT_NAME vix_os
    VERSION ${PROJECT_VERSION}
    SOVERSION 0
    EXPORT_NAME os
  )

  install(TARGETS vix_os
    EXPORT ${VIX_OS_EXPORT_SET}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )

else()
  message(STATUS "[os] Building HEADER-ONLY library (no sources).")

  add_library(vix_os INTERFACE)
  add_library(vix::os ALIAS vix_os)

  target_compile_features(vix_os INTERFACE cxx_std_20)

  target_include_directories(vix_os INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )

  target_link_libraries(vix_os INTERFACE
    ${VIX_ERROR_TARGET}
    ${VIX_PATH_TARGET}
  )

  install(TARGETS vix_os
    EXPORT ${VIX_OS_EXPORT_SET}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )
endif()

# --------------------------------------------------------------------
# Install headers
# --------------------------------------------------------------------
if (NOT (DEFINED VIX_UMBRELLA_BUILD AND VIX_UMBRELLA_BUILD))
  install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING
      PATTERN "*.hpp"
      PATTERN "*.h"
  )
endif()

# --------------------------------------------------------------------
# Standalone package config/export
# Only for non-umbrella builds
# --------------------------------------------------------------------
if (NOT (DEFINED VIX_UMBRELLA_BUILD AND VIX_UMBRELLA_BUILD))

  configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/vix_osConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/vix_osConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/vix_os"
  )

  write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/vix_osConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
  )

  install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/vix_osConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/vix_osConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/vix_os"
  )

  install(EXPORT vix_osTargets
    FILE vix_osTargets.cmake
    NAMESPACE vix::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/vix_os"
  )

endif()

# --------------------------------------------------------------------
# Tests
# --------------------------------------------------------------------
option(VIX_OS_BUILD_TESTS "Build os module tests" OFF)

if (VIX_OS_BUILD_TESTS)
  include(CTest)
  enable_testing()
  add_subdirectory(test)
endif()

# --------------------------------------------------------------------
# Summary
# --------------------------------------------------------------------
message(STATUS "------------------------------------------------------")
message(STATUS "vix::os configured (${PROJECT_VERSION})")
if (OS_SOURCES)
  message(STATUS "Mode: STATIC / sources found")
else()
  message(STATUS "Mode: HEADER-ONLY / no sources")
endif()
message(STATUS "Export set: ${VIX_OS_EXPORT_SET}")
message(STATUS "Error target: ${VIX_ERROR_TARGET}")
message(STATUS "Path target:  ${VIX_PATH_TARGET}")
message(STATUS "Include dir: ${CMAKE_CURRENT_SOURCE_DIR}/include (for <vix/os/...>)")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "------------------------------------------------------")
