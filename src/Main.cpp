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

    Echiquier e("echiquierDeBase.txt");
    e.afficher();


    string strDep, strBut;
    Coord dep, but;

    e.move(Coord(1,1),Coord(2,1));
    e.afficher();
    e.move(Coord(0,2),Coord(2,0));
    e.afficher();
    e.move(Coord(0,1),Coord(2,2));
    e.afficher();
    e.move(Coord(0,0),Coord(0,3));
    e.afficher();
    e.move(Coord(6,5),Coord(4,5));
    e.move(Coord(6,6),Coord(5,6));
    e.move(Coord(7,5),Coord(5,7));
    e.move(Coord(7,6),Coord(5,5));
    e.move(Coord(7,4),Coord(6,5));
    e.afficher();
    e.move(Coord(7,3),Coord(7,7));
    e.afficher();
/*
   for(int i=0; i < 10; ++i) {
      cout << "Selectionne la pièce à déplacer : ";
      cin >> strDep;
      cout << "Sélectionne la case d'arrivée : ";
      cin >> strBut;
      dep.getCoord(strDep);
      but.getCoord(strBut);
      e.move(dep,but);
      e.afficher();
    }
   */

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
