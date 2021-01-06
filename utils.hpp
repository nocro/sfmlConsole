#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <algorithm>

struct console_params
{
    sf::Vector2u window_size;
    
    sf::Vector2f tapping_zone_size;
    sf::Vector2f tapping_zone_origin;

    sf::Vector2f scroling_bar_size;
    sf::Vector2f scroling_bar_origin;


    sf::Color text_in_color;
    sf::Color text_out_color;
};


#endif