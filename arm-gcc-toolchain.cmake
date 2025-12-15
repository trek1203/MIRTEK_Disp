set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR arm)


set(arm_toolchain "Not Defined" CACHE PATH "Path to the arm toolchain folder.")


set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

if(UNIX)
    set(CMAKE_C_COMPILER /usr/bin/arm-none-eabi-gcc)
    set(CMAKE_CXX_COMPILER /usr/bin/arm-none-eabi-g++)
    set(CMAKE_ASM_COMPILER /usr/bin/arm-none-eabi-gcc)
    set(ARM_SIZE ${arm_toolchain}/bin/arm-none-eabi-size CACHE INTERNAL "")
elseif(WIN32)
    set(CMAKE_C_COMPILER   ${arm_toolchain}/bin/arm-none-eabi-gcc.exe CACHE INTERNAL "")
    set(CMAKE_CXX_COMPILER ${arm_toolchain}/bin/arm-none-eabi-g++.exe CACHE INTERNAL "")
    set(ARM_SIZE ${arm_toolchain}/bin/arm-none-eabi-size.exe CACHE INTERNAL "")
endif()

set(CMAKE_C_FLAGS_DEBUG "-g3 -Og -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-Os -DNDEBUG")
set(CMAKE_ASM_FLAGS "${CMAKE_C_FLAGS}" CACHE STRING "")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -Og -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-Os -DNDEBUG")

set(CMAKE_C_COMPILER_WORKS TRUE)
set(CMAKE_CXX_COMPILER_WORKS TRUE)
set(CMAKE_ASM_COMPILER_WORKS TRUE)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)