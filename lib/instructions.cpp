#include <iostream>
#include "constants.hpp"

/* all documentation for these functions is provided by:
Cogwoods Chip-8 Technical Reference v1.0
http://devernay.free.fr/hacks/chip8/C8TECH10.HTM#00E0
*/

void JP_1nnn(unsigned short *programCounter, unsigned short jumpDestination){
    *programCounter = jumpDestination;
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
void LD_6xkk(unsigned char * pRegister, unsigned char loadValue){
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
void ADD_7xkk(unsigned char * pRegister, unsigned char additionValue){
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
void LD_8xy0(unsigned char * pRegisterx, unsigned char * pRegistery){
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
void OR_8xy1(unsigned char * pRegisterx, unsigned char * pRegistery){
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
void AND_8xy2(unsigned char * pRegisterx, unsigned char * pRegistery){
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
void XOR_8xy3(unsigned char * pRegisterx, unsigned char * pRegistery){
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
void ADD_8xy4(unsigned char * pRegisterx, unsigned char * pRegistery, unsigned char * pRegisterF){

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