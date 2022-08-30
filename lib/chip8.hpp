#define MEMORYSIZE 0xFFF
#define REGISTERCOUNT 0xF

#include <logger.hpp>

class chip8{
    public:

        //program in RAM starts at 0x200
        unsigned short pc = 0x200;

        //unsigned char is an 8 bit datatype
        unsigned char memory[MEMORYSIZE] = {0};
        unsigned char generalRegisters[REGISTERCOUNT] = {0};

        /**
         * @brief  the first step in the Fetch, Decode, Execute process.
         *         gets the operation from the memory location passed, and immediately after,
         *         merges them into an unsigned short, and returns it.
         * @param  programCounter: the memory location to fetch from. 
         * @retval returnValue:
         */
        unsigned short fetch(unsigned short programCounter){
            
            unsigned short returnValue = 0;

            if(programCounter >= MEMORYSIZE){
                //returns 0 on this condition
                logger::log("attempted to fetch from a location larger than memory available.");
                //TODO stop the program in main on this error??
            }
            else{
                returnValue= memory[programCounter] << 8 | memory[programCounter + 1];
            }

            return returnValue;
        }
};