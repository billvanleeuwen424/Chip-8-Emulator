SET(TEST_SOURCES
    instructionTests.cpp
    ${CMAKE_SOURCE_DIR}/lib/instructions.cpp
)


add_executable(${TARGET_TEST_NAME} ${TEST_SOURCES})


#set up tests, get required libraries
target_link_libraries(${TARGET_TEST_NAME} PRIVATE Catch2::Catch2WithMain)

find_package(Catch2 REQUIRED)
include(Catch)

catch_discover_tests(${TARGET_TEST_NAME})

target_include_directories(${TARGET_TEST_NAME} PRIVATE ${INCLUDE_DIRS})