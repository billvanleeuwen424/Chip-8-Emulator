cmake_minimum_required(VERSION 3.22.0)
project(chip8EMU VERSION 0.1.0)

include(CTest)
enable_testing()

set(TARGET_NAME chip8)

set(SOURCES
    src/main.cpp
)
set(INCLUDE_DIRS
    ${PROJECT_SOURCE_DIR}/lib
)

add_executable(${TARGET_NAME} ${SOURCES})

target_include_directories(${TARGET_NAME} PUBLIC
"${PROJECT_BINARY_DIR}"
"${PROJECT_SOURCE_DIR}/lib"
)

# set up the tests
set(TARGET_TEST_NAME chip8Tests)
add_subdirectory(tests)
add_test(${TARGET_TEST_NAME} tests/${TARGET_TEST_NAME})