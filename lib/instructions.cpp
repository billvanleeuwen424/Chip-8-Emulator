#include <iostream>
#include "constants.hpp"
#include <stdint.h>

/* all documentation for these functions is provided by:
Cogwoods Chip-8 Technical Reference v1.0
http://devernay.free.fr/hacks/chip8/C8TECH10.HTM#00E0
*/

/**
 * @brief  
 * Jump to location nnn.
 * The interpreter sets the program counter to nnn. 
 * 
 * @param  *programCounter:  a pointer to the program counter
 * @param  jumpDestination: 16bit value to set the pc to
 * @retval None
 */
void JP_1nnn(uint16_t *programCounter, uint16_t jumpDestination){
    *programCounter = jumpDestination;
}

/**
 * @brief  
 * Call subroutine at nnn.
 * The interpreter increments the stack pointer, then puts the current PC on the top of the stack. The PC is then set to nnn.
 * 
 * @param  *programCounter: a pointer to the program counter
 * @param  stackPointer: the stack pointer
 * @param  callDestination: 16bit value to set the pc to
 * @retval None
 */
void CALL_2nnn(uint16_t *programCounter, uint16_t * stackPointer, uint16_t callDestination){

    *stackPointer = *programCounter;
    stackPointer++;

    *programCounter = callDestination;
}

/**
 * @brief  
 * Skip next instruction if Vx = kk.
 * The interpreter compares register Vx to kk, and if they are equal, increments the program counter by 2. 
 * 
 * @param  *programCounter: a pointer to the program counter
 * @param  pRegister: a pointer to the desired register
 * @param  checkValue: the value in which to check the register against
 * @retval None
 */
void SE_3xkk(uint16_t *programCounter, u_int8_t * pRegister, u_int8_t checkValue){

    if(*pRegister == checkValue){
        *programCounter += 2;
    }

}

/**
 * @brief  
 * Skip next instruction if Vx != kk.
 * The interpreter compares register Vx to kk, and if they are not equal, increments the program counter by 2.
 * 
 * @param  *programCounter: a pointer to the program counter
 * @param  pRegister: a pointer to the desired register
 * @param  checkValue: the value in which to check the register against
 * @retval None
 */
void SNE_4xkk(uint16_t *programCounter, u_int8_t * pRegister, u_int8_t checkValue){

    if(*pRegister != checkValue){
        *programCounter += 2;
    }

}

/**
 * @brief  
 * 6xkk - LD Vx, byte
 * Set Vx = kk.
 * The interpreter puts the value kk into register Vx.
 * 
 * @param  pRegister: a pointer to the deisred register
 * @param  loadValue:  the value to asign to that register
 */
void LD_6xkk(u_int8_t * pRegister, u_int8_t loadValue){
    *pRegister = loadValue;
}

/**
 * @brief 
 * 7xkk - ADD Vx, byte
 * Set Vx = Vx + kk.
 * Adds the value kk to the value of register Vx, then stores the result in Vx.
 * 
 * @param pRegister a pointer to the deisred register
 * @param additionValue the value to add to that register
 */
void ADD_7xkk(u_int8_t * pRegister, u_int8_t additionValue){
    *pRegister += additionValue;
}


/**
 * @brief   
 * Set Vx = Vy.
 * Stores the value of register Vy in register Vx.
 * 
 * @param  pRegisterx: a pointer to the desired set register
 * @param  pRegistery: a pointer to the register in which value you would like to set pRegisterx to
 */
void LD_8xy0(u_int8_t * pRegisterx, u_int8_t * pRegistery){
    *pRegisterx = *pRegistery;
}

/**
 * @brief  
 * Set Vx = Vx OR Vy.
 * Performs a bitwise OR on the values of Vx and Vy, then stores the result in Vx. 
 * A bitwise OR compares the corrseponding bits from two values, and if either bit is 1, then the same bit in the result is also 1. 
 * Otherwise, it is 0. 
 * 
 * @param  pRegisterx: a pointer to the desired set register
 * @param  pRegistery: a pointer to the register in which value you would like to OR pRegisterx to
 */
void OR_8xy1(u_int8_t * pRegisterx, u_int8_t * pRegistery){
    *pRegisterx = *pRegisterx | *pRegistery;
}

/**
 * @brief  
 * 8xy2 - AND Vx, Vy
 * Set Vx = Vx AND Vy.
 * Performs a bitwise AND on the values of Vx and Vy, then stores the result in Vx. 
 * A bitwise AND compares the corrseponding bits from two values, and if both bits are 1, 
 * then the same bit in the result is also 1. Otherwise, it is 0.
 * 
 * @param  pRegisterx: a pointer to the desired set register
 * @param  pRegistery: a pointer to the register in which value you would like to AND pRegisterx to
 * @param  pRegisterF: the 0xF register, used as carry
 * @retval None
 */
void AND_8xy2(u_int8_t * pRegisterx, u_int8_t * pRegistery){
    *pRegisterx = *pRegisterx & *pRegistery;

}

/**
 * @brief  
 * 8xy3 - XOR Vx, Vy
 * Set Vx = Vx XOR Vy.
 * Performs a bitwise exclusive OR on the values of Vx and Vy, then stores the result in Vx. 
 * An exclusive OR compares the corrseponding bits from two values, and if the bits are not both the same, 
 * then the corresponding bit in the result is set to 1. Otherwise, it is 0. 
 * 
 * @param  pRegisterx: a pointer to the desired set register
 * @param  pRegistery: a pointer to the register in which value you would like to XOR pRegisterx to
 * @retval None
 */
void XOR_8xy3(u_int8_t * pRegisterx, u_int8_t * pRegistery){
    *pRegisterx = *pRegisterx ^ *pRegistery;
}


/**
 * @brief  
 *  Set Vx = Vx + Vy, set VF = carry.
 * 
 * The values of Vx and Vy are added together. If the result is greater than 8 bits (i.e., > 255,) VF is set to 1, otherwise 0. 
 * Only the lowest 8 bits of the result are kept, and stored in Vx.
 * 
 * @param  pRegisterx: a pointer to the desired set register
 * @param  pRegistery: a pointer to the register in which value you would like to set pRegisterx to
 * @param  pRegisterF: the 0xF register, used as carry
 * @retval None
 */
void ADD_8xy4(u_int8_t * pRegisterx, u_int8_t * pRegistery, u_int8_t * pRegisterF){

    int additonValue = *pRegisterx + *pRegistery;

    if( additonValue > BYTE ){
        *pRegisterF = 1;
    }
    else{
        *pRegisterF = 0;
    }

    //get ONLY the lowest 8 bits of the value
    *pRegisterx = additonValue & 0xFF;
}

/**
 * @brief  
 * Display n-byte sprite starting at memory location I at (Vx, Vy), set VF = collision.
 * 
 * The interpreter reads n bytes from memory, starting at the address stored in I. 
 * These bytes are then displayed as sprites on screen at coordinates (Vx, Vy). 
 * Sprites are XORed onto the existing screen. If this causes any pixels to be erased, VF is set to 1, otherwise it is set to 0. 
 * If the sprite is positioned so part of it is outside the coordinates of the display, it wraps around to the opposite side of the screen. 
 * 
 * @param  xCoord starting x coordinates of sprite to be drawn
 * @param  yCoord starting y coordinates of sprite to be drawn
 * @param  pRegisterI a pointer to the I register, which stores the memory location of the sprite
 * @retval None
 */
void DRW_Dxyn(u_int8_t xCoord, u_int8_t yCoord, u_int8_t * pRegisterI){
    
}