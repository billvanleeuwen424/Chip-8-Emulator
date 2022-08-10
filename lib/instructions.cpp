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



void LD_8xy0(unsigned char * pRegisterx, unsigned char * pRegistery){
    *pRegisterx = *pRegistery;
}