#define MEMORYSIZE 4096
#define REGISTERCOUNT 0xF

struct chip8{
    public:

        //program in RAM starts at 0x200
        unsigned short pc = 0x200;

        //unsigned char is an 8 bit datatype
        unsigned char memory[MEMORYSIZE] = {0};
        unsigned char generalRegisters[REGISTERCOUNT] = {0};


        unsigned char fetch(unsigned short pc){
            return 0;
        }
};