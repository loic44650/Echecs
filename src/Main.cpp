#include <iostream>
#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Window.hpp"
#include "Echiquier.hpp"
#include "Piece.hpp"


using namespace std;


int main()
{
    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "Echecs", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
    
    sf::Image logo;
    logo.loadFromFile("picture/logo.png");
    app.setIcon(256, 256, logo.getPixelsPtr()); // ne fonctionne pas ?!?!

    Window window;
   	
    while (app.isOpen())
    {
        sf::Event event;

        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();
        }

        app.clear();
    	window.drawPlateauInitial(app);
        app.display();
    }
}