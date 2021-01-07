#include "console.hpp"


int main()
{
    Console console;
    
    while(console.isOpen())
    {
        std::cout << "etape 1\n";
        console.event();
        std::cout << "etape 2\n";
        console.draw();
        std::cout << "etape 3\n";
        console.update();
        std::cout << "etape 4\n";
    }
    return 0;
}