#include <catch2/catch_test_macros.hpp>

#include "chip8.hpp"
#include "constants.hpp"
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

TEST_CASE("8xy4 sets carry bit correctly and stores lowest 8 bits in Vx", "[8xy4 ADD]"){
    chip8 testChip;

    unsigned char *registerPointerx = &testChip.generalRegisters[0];
    unsigned char *registerPointery = &testChip.generalRegisters[1];

    unsigned char *registerPointerF = &testChip.generalRegisters[0xF];

    SECTION("Carry bit is set to 1 on result greater than 1 byte"){
        
        *registerPointerx = 25;
        *registerPointery = 255;

        ADD_8xy4(registerPointerx, registerPointery, registerPointerF);

        REQUIRE(testChip.generalRegisters[0xF] == 1);
    }

    SECTION("Carry bit is NOT set to 1 on results less than 1 byte"){

        *registerPointerx = 1;
        *registerPointery = 10;

        ADD_8xy4(registerPointerx, registerPointery, registerPointerF);

        REQUIRE_FALSE(testChip.generalRegisters[0xF] == 1);
    }

    SECTION("Vx is set to the lowest 8 bits of a result larger than 8 bits"){

        *registerPointerx = 25;
        *registerPointery = 255;

        ADD_8xy4(registerPointerx, registerPointery, registerPointerF);

        REQUIRE(testChip.generalRegisters[0] <= BYTE);
    }

    SECTION("Vx is set to the lowest 8 bits of a result less than 8 bits"){

        *registerPointerx = 1;
        *registerPointery = 10;

        ADD_8xy4(registerPointerx, registerPointery, registerPointerF);

        REQUIRE(testChip.generalRegisters[0] == 11);
    }
}