#include <catch2/catch_test_macros.hpp>

#include "chip8.hpp"
#include "constants.hpp"
#include "instructions.hpp"

TEST_CASE("1nnn modifies the program counter correctly"){
    chip8 testChip;

    SECTION("Modify PC to 0"){
        JP_1nnn(&testChip.pc, 0);

        REQUIRE(testChip.pc == 0);
    }

    SECTION("Modify PC to 0xFFF"){
        JP_1nnn(&testChip.pc, 0xFFF);

        REQUIRE(testChip.pc == 0xFFF);
    }
    
}

TEST_CASE("2nnn modifies the stack, and program counter correctly"){
    chip8 testChip;

    SECTION("Modify the program counter correctly"){
        CALL_2nnn(&testChip.pc, testChip.stackPointer, 0x202);

        REQUIRE(testChip.pc == 0x202);
    }

    SECTION("Modify the stack pointer correctly"){

        unsigned short *originalStackPointerLocation = testChip.stackPointer;

        CALL_2nnn(&testChip.pc, testChip.stackPointer, 0x202);

        REQUIRE(testChip.stackPointer == originalStackPointerLocation++);
    }

    SECTION("The stack has the correct memory address stored"){
        testChip.pc = 0x200;

        CALL_2nnn(&testChip.pc, testChip.stackPointer, 0x202);

        REQUIRE(testChip.stack[0] == 0x200);
    }
}

TEST_CASE("3xkk modifies program counter correctly"){
    chip8 testChip;

    SECTION("Modify the program counter when equal"){

        testChip.pc = 0x200;
        testChip.generalRegisters[0] = 0xA;

        SE_3xkk(&testChip.pc, &testChip.generalRegisters[0], 0xA);

        REQUIRE(testChip.pc == 0x202);
    }

    SECTION("Do NOT modify the program counter when NOT equal"){

        testChip.pc = 0x200;
        testChip.generalRegisters[0] = 0xB;

        SE_3xkk(&testChip.pc, &testChip.generalRegisters[0], 0xA);

        REQUIRE(testChip.pc == 0x200);
    }

}

TEST_CASE("4xkk modifies program counter correctly"){
    chip8 testChip;

    SECTION("Modify the program counter when NOT equal"){

        testChip.pc = 0x200;
        testChip.generalRegisters[0] = 0xA;

        SNE_4xkk(&testChip.pc, &testChip.generalRegisters[0], 0xA);

        REQUIRE(testChip.pc == 0x200);
    }

    SECTION("Do NOT Modify the program counter when equal"){

        testChip.pc = 0x200;
        testChip.generalRegisters[0] = 0xB;

        SNE_4xkk(&testChip.pc, &testChip.generalRegisters[0], 0xA);

        REQUIRE(testChip.pc == 0x202);
    }

}

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

TEST_CASE("8xy1 logical OR's the value of x register correctly, and leaves y register alone", "[8xy1 OR]"){
    chip8 testChip;

    unsigned char *registerPointerx = &testChip.generalRegisters[0];
    unsigned char *registerPointery = &testChip.generalRegisters[1];

    SECTION("OR, input: X==1, Y==1. output:X==1, Y==1"){
        *registerPointerx = 1;
        *registerPointery = 1;

        OR_8xy1(registerPointerx, registerPointery);

        REQUIRE(*registerPointerx == 1);
        REQUIRE(*registerPointery == 1);
    }

    SECTION("OR, input: X==0, Y==1. output:X==1, Y==1"){
        *registerPointerx = 0;
        *registerPointery = 1;

        OR_8xy1(registerPointerx, registerPointery);

        REQUIRE(*registerPointerx == 1);
        REQUIRE(*registerPointery == 1);
    }

    SECTION("OR, input: X==1, Y==0. output:X==1, Y==0"){
        *registerPointerx = 1;
        *registerPointery = 0;

        OR_8xy1(registerPointerx, registerPointery);

        REQUIRE(*registerPointerx == 1);
        REQUIRE(*registerPointery == 0);
    }

    SECTION("OR, input: X==170 (10101010), Y==85 (01010101). output:X==255 (11111111), Y==85"){
        *registerPointerx = 170;
        *registerPointery = 85;

        OR_8xy1(registerPointerx, registerPointery);

        REQUIRE(*registerPointerx == 255);
        REQUIRE(*registerPointery == 85);
    }
}

TEST_CASE("8xy2 logical AND's the value of register x and leaves register y alone.", "[8xy2 AND]"){
    chip8 testChip;

    unsigned char *registerPointerx = &testChip.generalRegisters[0];
    unsigned char *registerPointery = &testChip.generalRegisters[1];

    SECTION("AND, input X==255 (11111111), y==255 (11111111). output X==255 (11111111), y==255 (11111111)"){

        *registerPointerx = 0xFF;
        *registerPointery = 0xFF;

        AND_8xy2(registerPointerx, registerPointery);

        REQUIRE(*registerPointerx == 0xFF);
        REQUIRE(*registerPointery == 0xFF);
    }
    

    SECTION("AND, input X==170 (10101010), y==85 (01010101). output X==0 (00000000), y==85 (01010101)"){
        *registerPointerx = 0xAA;
        *registerPointery = 0x55;

        AND_8xy2(registerPointerx, registerPointery);

        REQUIRE(*registerPointerx == 0);
        REQUIRE(*registerPointery == 0x55);
    }

    SECTION("AND, input X==85 (01010101), y==85 (01010101). output X==85 (01010101), y==85 (01010101)"){
        *registerPointerx = 0x55;
        *registerPointery = 0x55;

        AND_8xy2(registerPointerx, registerPointery);

        REQUIRE(*registerPointerx == 0x55);
        REQUIRE(*registerPointery == 0x55);
    }



}


TEST_CASE("8XY3 XOR's the value of register x correctly and leaves register y alone"){
    chip8 testChip;

    unsigned char *registerPointerx = &testChip.generalRegisters[0];
    unsigned char *registerPointery = &testChip.generalRegisters[1];   

    SECTION("XOR, input X==255 (11111111), y==255 (11111111). output X==0 (00000000), y==255 (11111111)"){

        *registerPointerx = 0xFF;
        *registerPointery = 0xFF;

        XOR_8xy3(registerPointerx, registerPointery);

        REQUIRE(*registerPointerx == 0);
        REQUIRE(*registerPointery == 0xFF);
    }
    

    SECTION("XOR, input X==170 (10101010), y==85 (01010101). output X==255 (11111111), y==85 (01010101)"){
        *registerPointerx = 0xAA;
        *registerPointery = 0x55;

        XOR_8xy3(registerPointerx, registerPointery);

        REQUIRE(*registerPointerx == 0xFF);
        REQUIRE(*registerPointery == 0x55);
    }

    SECTION("XOR, input X==85 (01010101), y==85 (01010101). output X==0 (00000000), y==85 (01010101)"){
        *registerPointerx = 0x55;
        *registerPointery = 0x55;

        XOR_8xy3(registerPointerx, registerPointery);

        REQUIRE(*registerPointerx == 0);
        REQUIRE(*registerPointery == 0x55);
    }
}


TEST_CASE("8xy4 sets carry bit correctly and stores lowest 8 bits in Vx. Modifys overflow correctly.", "[8xy4 ADD]"){
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