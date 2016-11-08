#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Window.hpp"
#include "Echiquier.hpp"
#include "Joueur.hpp"
#include "Piece.hpp"
#include "utils.hpp"


using namespace std;

int main()
{

    string nom, prenom;
    char col;

    cout << "Saisissez votre nom." << endl;
    cin >> nom;
    cout << "Saisissez votre prenom." << endl;
    cin >> prenom;
    cout << "Saisissez votre couleur (N / B)." << endl;
    cin >> col;

    Joueur joueur1(nom, prenom, col);

    if (joueur1.getCouleur() == 'N') Echiquier e("echiquierDeBaseN.txt");
    else if (joueur1.getCouleur() == 'B') Echiquier e("echiquierDeBaseB.txt");


    /*string strDep, strBut;
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
    e.afficher();*/
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
    Echiquier e("echiquierDeBaseN.txt");

    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "Echecs", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);

    sf::Image logo;
    logo.loadFromFile("picture/logo.png");
    app.setIcon(256, 256, logo.getPixelsPtr()); // ne fonctionne pas ?!?!

    Window window;
    
    cout << "bob" << endl;

    while (app.isOpen())
    {
        sf::Event event;
        cout << "bob1" << endl;

        while (app.pollEvent(event))
        {

            cout << "bob2" << endl;

            if (event.type == sf::Event::Closed)
                app.close();

            cout << "bob3" << endl;

        }

        app.clear();
    	window.drawPlateau(app, e);
        app.display();
    }
    */
}
