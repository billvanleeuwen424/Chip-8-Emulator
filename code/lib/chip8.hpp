#define MEMORYSIZE 4096
#define REGISTERCOUNT 16

class chip8{
    //unsigned char is an 8 bit datatype
    unsigned char memory[MEMORYSIZE];
    unsigned char registers[REGISTERCOUNT];
};