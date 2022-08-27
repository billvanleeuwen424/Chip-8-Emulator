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
         *         gets the data from the memory location in question, and returns it.
         * @param  programCounter: the memory location to fetch from. 
         * @retval returnValue:
         */
        unsigned char fetch(unsigned short programCounter){
            
            unsigned char returnValue = 0;

            if( !(programCounter > MEMORYSIZE) ){
                returnValue = memory[programCounter];
            }
            else{
                //returns 0 on this condition
                logger::log("attempted to fetch from a location larger than memory available.");

                //TODO stop the program in main on this error??
            }

            return returnValue;
        }
};