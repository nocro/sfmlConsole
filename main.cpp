#include "console.hpp"


int main()
{
    Console console;
    
    while(console.isOpen())
    {
        console.event();
        console.draw();
        console.update();
    }
    return 0;
}