#include <catch2/catch_test_macros.hpp>

#include "chip8.hpp"
#include "constants.hpp"

TEST_CASE("Test the Fetch method"){
    chip8 testChip;

    SECTION("Get opcode correctly from supplied memory location"){

        testChip.memory[0x200] = 0x71;    //7xkk - ADD. add 55 into register 1
        testChip.memory[0x201] = 0x55; 

        REQUIRE(0x7155 == testChip.fetch(0x200));
    }

    SECTION("Returns 0 when trying to access over 0xFFFF (top size of memory)"){
        REQUIRE(testChip.fetch(MEMORYSIZE+1) == 0);
    }
    
}
