#include <catch2/catch_test_macros.hpp>

#include "chip8.hpp"
#include "instructions.hpp"

TEST_CASE("7xkk Modified the passed register correctly", "[7xkk ADD]"){
    chip8 testChip;

    SECTION("modify the correct register"){

        unsigned char *registerPointer = &testChip.generalRegisters[0];

        //add 1 to the 0 register
        ADD_7xkk(registerPointer, 1);

        REQUIRE(testChip.generalRegisters[0] == 1);

    }
    
};
