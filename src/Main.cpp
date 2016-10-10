#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "Window.hpp"
#include "Echiquier.hpp"
#include "Piece.hpp"


using namespace std;


int main()
{
	//Echiquier e;
	//e.afficher();
	

    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "Echecs", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);

    Window window;

   	while (app.isOpen())
    {
        sf::Event event;

        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();
        }

        app.clear(sf::Color(187, 174, 152));
    	window.drawPlateauInitial(app);
        app.display();
    }
}
