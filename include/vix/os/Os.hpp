/**
 *
 *  @file Os.hpp
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
#ifndef VIX_OS_OS_HPP
#define VIX_OS_OS_HPP

// Foundations
#include <vix/os/OsError.hpp>
#include <vix/os/OsResult.hpp>
#include <vix/os/OsInfo.hpp>
#include <vix/os/UserInfo.hpp>
#include <vix/os/CpuInfo.hpp>
#include <vix/os/MemoryInfo.hpp>

// System identification
#include <vix/os/Platform.hpp>
#include <vix/os/Arch.hpp>
#include <vix/os/KernelVersion.hpp>
#include <vix/os/Hostname.hpp>

// User & process
#include <vix/os/CurrentUser.hpp>
#include <vix/os/CurrentPid.hpp>
#include <vix/os/IsAdmin.hpp>

// Directories
#include <vix/os/HomeDir.hpp>
#include <vix/os/TempDir.hpp>

// System resources
#include <vix/os/PageSize.hpp>
#include <vix/os/CpuCount.hpp>
#include <vix/os/Uptime.hpp>

// Utilities
#include <vix/os/Sleep.hpp>

#endif // VIX_OS_OS_HPP
