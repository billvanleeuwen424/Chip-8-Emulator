void JP_1nnn(u_int16_t *programCounter, u_int16_t jumpDestination);

void CALL_2nnn(u_int16_t *programCounter, u_int16_t * stackPointer, u_int16_t callDestination);

void SE_3xkk(u_int16_t *programCounter, u_int8_t * pRegister, u_int8_t checkValue);

void SNE_4xkk(u_int16_t *programCounter, u_int8_t * pRegister, u_int8_t checkValue);

void LD_6xkk(u_int8_t * pRegister, u_int8_t loadValue);

void ADD_7xkk( u_int8_t * pRegister, u_int8_t additionValue);

void LD_8xy0(u_int8_t * pRegisterx, u_int8_t * pRegistery);

void OR_8xy1(u_int8_t * pRegisterx, u_int8_t * pRegistery);

void AND_8xy2(u_int8_t * pRegisterx, u_int8_t * pRegistery);

void XOR_8xy3(u_int8_t * pRegisterx, u_int8_t * pRegistery);

void ADD_8xy4(u_int8_t * pRegisterx, u_int8_t * pRegistery, u_int8_t * pRegisterF);