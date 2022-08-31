#define MEMORYSIZE 0xFFF
#define REGISTERCOUNT 0xF
#define STACKSIZE 0xF

#include <logger.hpp>
#include "instructions.hpp"

class chip8{
    public:

        //program in RAM starts at 0x200
        unsigned short pc = 0x200;

        //unsigned char is an 8 bit datatype
        unsigned char memory[MEMORYSIZE] = {0};
        unsigned char generalRegisters[REGISTERCOUNT] = {0};
        
        unsigned short stack[STACKSIZE] = {0};
        unsigned short * stackPointer = &stack[0]; 

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

        /**
         * @brief  the second and third step in the Fetch, Decode, Execute process.
         *         takes a full 16bit opcode, decodes which instruction to execute, and does so. 
         * @note   
         * @param  opcode: 16bit opcode fetched from memory
         * @retval None
         */
        void decodeExecute(unsigned short opcode){
            switch (opcode & 0xF000)
            {
            case 0x1000:
                break;
            case 0x2000:
                break;
            case 0x3000:
                break;
            case 0x4000:
                break;
            case 0x5000:
                break;
            case 0x6000:
                break;
            case 0x7000:
                break;

            case 0x8000:

                switch (opcode & 0x000F)
                {
                case 0x0000:
                    LD_8xy0(&generalRegisters[opcode >> 8 & 0xF], &generalRegisters[opcode >> 4 & 0xF]);
                    break;
                case 0x0001:
                    OR_8xy1(&generalRegisters[opcode >> 8 & 0xF], &generalRegisters[opcode >> 4 & 0xF]);
                    break;
                case 0x0002:
                    AND_8xy2(&generalRegisters[opcode >> 8 & 0xF], &generalRegisters[opcode >> 4 & 0xF]);
                    break;
                case 0x0003:
                    XOR_8xy3(&generalRegisters[opcode >> 8 & 0xF], &generalRegisters[opcode >> 4 & 0xF]);
                    break;
                case 0x0004:
                    ADD_8xy4(&generalRegisters[opcode >> 8 & 0xF], &generalRegisters[opcode >> 4 & 0xF], &generalRegisters[0xF]);
                    break;
                case 0x0005:
                    break;
                case 0x0006:
                    break;
                case 0x0007:
                    break;
                case 0x000E:
                    break;

                default:
                    break;
                }

                break;
            case 0x9000:
                break;
            case 0xA000:
                break;
            case 0xB000:
                break;
            case 0xC000:
                break;
            case 0xD000:
                break;
            case 0xE000:
                break;
            case 0xF000:
                break;
            
            default:
                break;
            }  
        }
};