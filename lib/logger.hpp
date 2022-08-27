#include <iostream>
#include <string>


class logger
{
    public:
        static void log(std::string message){
            std::cout << message << "\n";
        }
};
