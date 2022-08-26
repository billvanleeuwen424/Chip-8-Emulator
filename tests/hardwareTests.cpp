#include <catch2/catch_test_macros.hpp>

#include "chip8.hpp"
#include "constants.hpp"

TEST_CASE("Test the Fetch method"){
    chip8 testChip;

    SECTION("Get data correctly at supplied memory location"){

        testChip.memory[0x200] = 5;

        REQUIRE(5 == testChip.fetch(0x200));
    }

    SECTION("Throw exception on access less than 0x200 (reserved memory)"){

    }

    SECTION("Throw exception on access greater than 0xFFFF (top size of memory)"){

    }
    
}