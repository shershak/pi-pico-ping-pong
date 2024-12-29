# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(ping_pong C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(ping_pong 
        ping_pong.cpp
        core/buttons/ButtonManager.cpp
        core/display/DisplayManager.cpp
        ecs/EntityManager.cpp
)

pico_set_program_name(ping_pong "ping_pong")
pico_set_program_version(ping_pong "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(ping_pong 0)
pico_enable_stdio_usb(ping_pong 1)

add_subdirectory(core/display/driver)

# Add the standard library to the build
target_link_libraries(ping_pong pico_stdlib)

# Add the standard include files to the build
target_include_directories(ping_pong PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/core/buttons
  ${CMAKE_CURRENT_LIST_DIR}/core/display
  ${CMAKE_CURRENT_LIST_DIR}/ecs
)

# Add any user requested libraries
target_link_libraries(ping_pong 
        hardware_i2c
        hardware_pio
        pico_ssd1306
        )

pico_add_extra_outputs(ping_pong)