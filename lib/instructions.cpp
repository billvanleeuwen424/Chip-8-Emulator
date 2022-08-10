#include <iostream>
#include "constants.hpp"

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



void ADD_8xy4(unsigned char * pRegisterx, unsigned char * pRegistery, unsigned char * pRegisterF){

    int additonValue = *pRegisterx + *pRegistery;

    std::cout << additonValue;
    if( additonValue > BYTE ){
        *pRegisterF = 1;
    }
    else{
        *pRegisterF = 0;
    }
}