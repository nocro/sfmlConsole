#ifndef CONSOLE_HPP
#define CONSOLE_HPP
#include "utils.hpp"

class Console
{
private:
    std::vector<std::string> out;
    std::string input;
    sf::RenderWindow window;
    sf::Font font;
    sf::Text text_out;
    sf::Text text_in;
    sf::RectangleShape tapping_zone;
    sf::RectangleShape scroling_bar;

    std::vector<sf::VideoMode> modes;
    std::vector<console_params> modes_param;
    unsigned int activated_mode;
    unsigned int last_string_printed;

    void updateScrolingBarPos();


public:
    Console();
    //~Console();

    void add(std::string s);
    void draw();
    bool isOpen()
    {
        return window.isOpen();
    }
    bool event();
    void update();
    void switch_mode();


};



#endif