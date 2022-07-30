
/**
 * @brief 
 * 7xkk - ADD Vx, byte
 * Set Vx = Vx + kk.
 * Adds the value kk to the value of register Vx, then stores the result in Vx.
 * 
 * @param pRegister a pointer to the deisred register
 * @param additionValue the value to add to that register
 */
void ADD_7xkk( unsigned char * pRegister, unsigned char additionValue){
    *pRegister += additionValue;
}