#include "console.hpp"




Console::Console(): text_out("",font), text_in("",font), last_string_printed(0)
{
    font.loadFromFile("arial.ttf");

    modes.push_back(sf::VideoMode::getFullscreenModes()[0]);
    activated_mode = 0;
    if(!modes[0].isValid())
    {
        std::cout << "attention ce mode n'est pas valid\n";
        modes.push_back(sf::VideoMode(800, 600));
        activated_mode = 1;
        if (!modes[1].isValid())
        {
            std::cout << "bon mdr wtf" << std::endl;
        }
        else
        {
            std::cout << "tout va bien" << std::endl;
        }
    }
    window.create(modes[activated_mode],"loup garou");
    

    console_params param_mode;
    param_mode.window_size = window.getSize();
    param_mode.tapping_zone_size = sf::Vector2f(param_mode.window_size.x, param_mode.window_size.y/27);
    param_mode.tapping_zone_origin = sf::Vector2f(0, 
        param_mode.tapping_zone_size.y-param_mode.window_size.y);

    param_mode.scroling_bar_size = sf::Vector2f(param_mode.window_size.x/64, 
                param_mode.window_size.y-param_mode.tapping_zone_size.y);
    param_mode.scroling_bar_origin = sf::Vector2f(param_mode.scroling_bar_size.x-param_mode.window_size.x,0);


    param_mode.text_in_color = sf::Color(255,0,255,255);
    param_mode.text_out_color = sf::Color(0,255,0,255);

    tapping_zone.setSize(param_mode.tapping_zone_size);
    tapping_zone.setOrigin(param_mode.tapping_zone_origin);

    
    scroling_bar.setOrigin(param_mode.scroling_bar_origin);
    scroling_bar.setSize(param_mode.scroling_bar_size);
    scroling_bar.setFillColor(sf::Color(128,128,128,128));

    text_in.setFillColor(param_mode.text_in_color);
    text_in.setOrigin(param_mode.tapping_zone_origin);
    text_out.setFillColor(param_mode.text_out_color);

    modes_param.push_back(param_mode);
}


void Console::add(std::string s)
{
    out.push_back(s);
    last_string_printed++;
    if(out.size()>27)
    {
        /** update de la taille puis de la position de la scroling bar **/
        float y = modes_param[activated_mode].scroling_bar_size.y;
        float ysize = (27.0/static_cast<float>(out.size()))*y ;
        scroling_bar.setSize(sf::Vector2f( modes_param[activated_mode].scroling_bar_size.x , ysize));
        float distance = (static_cast<float>( out.size() - last_string_printed) / static_cast<float>(out.size()-27));
        float oy = (1.0-distance) * (y-ysize);
        scroling_bar.setOrigin(sf::Vector2f( modes_param[activated_mode].scroling_bar_origin.x, -oy));
    }
}
    

void Console::draw()
{
    window.clear();
    
    std::string toprint=" ";
    auto m = std::max(0,static_cast<int>(last_string_printed-27));
    for(long unsigned int i= m; i<last_string_printed; i++ )
    {
        toprint += out[i] +"\n";
    }
    std::cout << " caca : " << toprint.size() << std::endl;
    text_out.setString(toprint);
    window.draw(text_out);
    window.draw(tapping_zone);
    window.draw(text_in);
    window.draw(scroling_bar);
}

bool Console::event()
{
    sf::Event event;
    if (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed )
        {
            window.close();
        }
        else if (event.type == sf::Event::TextEntered)
        {
            if (event.text.unicode < 128)
            {   
                // std::cout << "char enter "<< event.text.unicode <<std::endl;
                if(event.text.unicode == 8)
                {
                    if (input != "")
                        input.pop_back();
                }
                else if(event.text.unicode == 13)
                {
                    add(input);
                    input = "";
                }
                else
                {
                    char newchar = static_cast<char>(event.text.unicode);
                    input += newchar;
                }  
                text_in.setString(input);
            }
        }
        else if(event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up)
            {
                if(last_string_printed > 27)
                    last_string_printed--;
                updateScrolingBarPos();
            }
            else if(event.key.code == sf::Keyboard::Down)
            {
                if(last_string_printed < out.size())
                {
                    last_string_printed++;
                    updateScrolingBarPos();
                }      
            }
        }
        return true;
    }
    return false;
}

void Console::update()
{
    window.display();
}

void Console::switch_mode()
{
    activated_mode = (activated_mode + 1) % modes.size();
    std::cout << "switch mode "<< activated_mode << "\n";
    window.create(modes[activated_mode], "loup garou");
}


void Console::updateScrolingBarPos()
{
    if(out.size()>27)
    {
        /** update de la position de la scroling bar **/
        
        float y = modes_param[activated_mode].scroling_bar_size.y;
        float ysize = (27.0/static_cast<float>(out.size()))*y ;
        
        
        float distance = (static_cast<float>( out.size() - last_string_printed) / static_cast<float>(out.size()-27));
        float oy = (1.0-distance) * (y-ysize);
        scroling_bar.setOrigin(sf::Vector2f( modes_param[activated_mode].scroling_bar_origin.x
                            , -oy));
    }
}
