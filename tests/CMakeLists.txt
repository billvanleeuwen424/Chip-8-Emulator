SET(INSTRUCTION_TEST_SOURCES
    instructionTests.cpp
    ${CMAKE_SOURCE_DIR}/lib/instructions.cpp
)

SET(HARDWARE_TEST_SOURCES
    ${CMAKE_SOURCE_DIR}/lib/instructions.cpp
    hardwareTests.cpp
)

add_executable(${TARGET_INSTRUCTIONS_TEST_NAME} ${INSTRUCTION_TEST_SOURCES})
add_executable(${TARGET_HARDWARE_TEST_NAME} ${HARDWARE_TEST_SOURCES})

find_package(Catch2 REQUIRED)
include(Catch)

#set up tests, get required libraries
target_link_libraries(${TARGET_INSTRUCTIONS_TEST_NAME} PRIVATE Catch2::Catch2WithMain)
target_link_libraries(${TARGET_HARDWARE_TEST_NAME} PRIVATE Catch2::Catch2WithMain)


catch_discover_tests(${TARGET_INSTRUCTIONS_TEST_NAME} ${TARGET_HARDWARE_TEST_NAME})

target_include_directories(${TARGET_INSTRUCTIONS_TEST_NAME} PRIVATE ${INCLUDE_DIRS})
target_include_directories(${TARGET_HARDWARE_TEST_NAME} PRIVATE ${INCLUDE_DIRS})