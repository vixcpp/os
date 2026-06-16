function(vix_os_add_test test_name test_source)
  add_executable(${test_name}
    ${test_source}
  )

  target_compile_features(${test_name}
    PRIVATE
      cxx_std_20
  )

  target_link_libraries(${test_name}
    PRIVATE
      vix::os
  )

  if (VIX_ENABLE_SANITIZERS AND NOT MSVC)
    target_compile_options(${test_name}
      PRIVATE
        -fno-omit-frame-pointer
        -fsanitize=address,undefined
    )

    target_link_options(${test_name}
      PRIVATE
        -fsanitize=address,undefined
    )
  endif()

  add_test(
    NAME ${test_name}
    COMMAND ${test_name}
  )
endfunction()

vix_os_add_test(vix_os_hostname_test hostname_test.cpp)
vix_os_add_test(vix_os_platform_test platform_test.cpp)
vix_os_add_test(vix_os_arch_test arch_test.cpp)
vix_os_add_test(vix_os_kernel_version_test kernel_version_test.cpp)
vix_os_add_test(vix_os_home_dir_test home_dir_test.cpp)
vix_os_add_test(vix_os_temp_dir_test temp_dir_test.cpp)
vix_os_add_test(vix_os_current_user_test current_user_test.cpp)
vix_os_add_test(vix_os_current_pid_test current_pid_test.cpp)
vix_os_add_test(vix_os_page_size_test page_size_test.cpp)
vix_os_add_test(vix_os_cpu_count_test cpu_count_test.cpp)
vix_os_add_test(vix_os_uptime_test uptime_test.cpp)
vix_os_add_test(vix_os_sleep_test sleep_test.cpp)
vix_os_add_test(vix_os_is_admin_test is_admin_test.cpp)
