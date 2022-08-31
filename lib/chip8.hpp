#define MEMORYSIZE 0xFFF
#define REGISTERCOUNT 0xF

#include <logger.hpp>
#include "instructions.hpp"

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

        void decodeExecute(unsigned short opcode){
        
            switch (opcode & 0xF000)
            {
            case 0x100:
                break;
            case 0x200:
                break;
            case 0x300:
                break;
            case 0x400:
                break;
            case 0x500:
                break;
            case 0x600:
                break;
            case 0x700:
                break;
            case 0x800:
                break;
            case 0x900:
                break;
            case 0xA00:
                break;
            case 0xB00:
                break;
            case 0xC00:
                break;
            case 0xD00:
                break;
            case 0xE00:
                break;
            case 0xF00:
                break;
            
            default:
                break;
            }  
        }
};