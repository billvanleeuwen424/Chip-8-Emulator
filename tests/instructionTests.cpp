#include <catch2/catch_test_macros.hpp>
#include <stdio.h>

#include "chip8.hpp"
#include "instructions.hpp"

TEST_CASE("7xkk Modified the passed register correctly", "[7xkk ADD]"){
    chip8 testChip;

    unsigned char *registerPointer = &testChip.generalRegisters[0];

    SECTION("Modify the correct register by 1"){


        //add 1 to the 0 register
        ADD_7xkk(registerPointer, 1);

        REQUIRE(testChip.generalRegisters[0] == 1);

    }

    SECTION("Rollover register when x + kk > 255"){
        //set register to max value 255
        ADD_7xkk(registerPointer, 255);
        REQUIRE(testChip.generalRegisters[0] == 255);
        
        //roll 255 + 2 should == 1
        ADD_7xkk(registerPointer, 2);
        REQUIRE(testChip.generalRegisters[0] == 1);

        //roll 1 + 255 should == 0
        ADD_7xkk(registerPointer, 255);
        REQUIRE(testChip.generalRegisters[0] == 0);


    }
    
};

TEST_CASE("6xkk Modified the passed register correctly", "[6xkk LD]"){
    chip8 testChip;

    unsigned char *registerPointer = &testChip.generalRegisters[0];

    SECTION("Load 255 into register 0"){

        LD_6xkk(registerPointer, 255);
        REQUIRE(testChip.generalRegisters[0] == 255);

    }

    //test that the value changes properly
    SECTION("Load 0 into register 0"){

        LD_6xkk(registerPointer, 0);
        REQUIRE(testChip.generalRegisters[0] == 0);
        
    }

}

TEST_CASE("8xy0 Loads the value of another register correctly", "[8xy0 LD]"){
    chip8 testChip;

    unsigned char *registerPointerx = &testChip.generalRegisters[0];
    unsigned char *registerPointery = &testChip.generalRegisters[1];

    SECTION("Register x is set correctly to the value of register y"){

        *registerPointery = 1;

        LD_8xy0(registerPointerx, registerPointery);

        REQUIRE(testChip.generalRegisters[0] == 1);
    }
}