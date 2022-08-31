void JP_1nnn(unsigned short *programCounter, unsigned short jumpDestination);

void CALL_2nnn(unsigned short *programCounter, unsigned short * stackPointer, unsigned short callDestination);

void LD_6xkk(unsigned char * pRegister, unsigned char loadValue);

void ADD_7xkk( unsigned char * pRegister, unsigned char additionValue);

void LD_8xy0(unsigned char * pRegisterx, unsigned char * pRegistery);

void OR_8xy1(unsigned char * pRegisterx, unsigned char * pRegistery);

void AND_8xy2(unsigned char * pRegisterx, unsigned char * pRegistery);

void XOR_8xy3(unsigned char * pRegisterx, unsigned char * pRegistery);

void ADD_8xy4(unsigned char * pRegisterx, unsigned char * pRegistery, unsigned char * pRegisterF);