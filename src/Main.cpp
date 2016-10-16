#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Window.hpp"
#include "Echiquier.hpp"
#include "Piece.hpp"
#include "utils.hpp"


using namespace std;

int main()
{

    Echiquier e;
    e.afficher();
    string strDep, strBut;
    Coord dep, but;



   for(int i=0; i < 10; ++i) {
      cout << "Selectionne la pièce à déplacer : ";
      cin >> strDep;
      cout << "Sélectionne la case d'arrivée : ";
      cin >> strBut;
      dep.getCoord(strDep);
      but.getCoord(strBut);
      e.move(dep,but);
      e.afficher();
      e.count_ptr();
   }


    /*
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
    */
}
