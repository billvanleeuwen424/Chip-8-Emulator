cmake_minimum_required(VERSION 3.22.0)
project(chip8EMU VERSION 0.1.0)

include(CTest)
enable_testing()

set(TARGET_NAME chip8)

set(SOURCES
    src/main.cpp
    lib/chip8.hpp
    lib/instructions.hpp
    lib/constants.hpp
    lib/logger.hpp
)
set(INCLUDE_DIRS
    ${PROJECT_SOURCE_DIR}/lib
)

add_executable(${TARGET_NAME} ${SOURCES})

target_include_directories(${TARGET_NAME} PUBLIC
${PROJECT_BINARY_DIR}
${PROJECT_SOURCE_DIR}/lib
)

# set up the tests
set(TARGET_INSTRUCTIONS_TEST_NAME InstructionTests)
set(TARGET_HARDWARE_TEST_NAME HardwareTests)

add_subdirectory(tests)
add_test(${TARGET_INSTRUCTIONS_TEST_NAME} tests/${TARGET_INSTRUCTIONS_TEST_NAME})
add_test(${TARGET_HARDWARE_TEST_NAME} tests/${TARGET_HARDWARE_TEST_NAME})