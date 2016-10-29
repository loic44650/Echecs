#include "Window.hpp"

Window::Window()
{
    plateau.loadFromFile("picture/plateau.png");
	pion.loadFromFile("picture/pion.png");
    tour.loadFromFile("picture/tour.png");
    fou.loadFromFile("picture/fou.png");
    cavalier.loadFromFile("picture/cavalier.png");
    reine.loadFromFile("picture/reine.png");
    roi.loadFromFile("picture/roi.png");
}

Window::~Window() {}

void Window::drawPlateau(sf::RenderTarget& app, Echiquier& e)
{
	sf::Sprite spritePlateau;
    spritePlateau.setTexture(plateau);
    spritePlateau.setScale(75, 75);

    sf::Sprite spritePiece;
    spritePiece.setScale(0.5, 0.5);

    app.draw(spritePlateau);

    Coord dep;

    for (int x = 0; x < 8; ++x)
    {
    	for (int y = 0; y < 8; ++y)
    	{
               
            dep = Coord(x, y);

            // Pieces blanches

   			if ((e.getType(dep) == 'T') && (e.getCouleur(dep) == 'N')) // tours noirs
   			{
   				spritePiece.setTexture(tour);
   				spritePiece.setColor(sf::Color(0, 0, 0));
   				spritePiece.setPosition(x * 75, y * 75);
   			}

   			if ((e.getType(dep) == 'F') && (e.getCouleur(dep) == 'N')) // fous noirs
   			{
   				spritePiece.setTexture(fou);
                spritePiece.setColor(sf::Color(0, 0, 0));
                spritePiece.setPosition(x * 75, y * 75);
   			}

			if ((e.getType(dep) == 'C') && (e.getCouleur(dep) == 'N')) // cavaliers noirs
   			{
   				spritePiece.setTexture(cavalier);
                spritePiece.setColor(sf::Color(0, 0, 0));
   				spritePiece.setPosition(x * 75, y * 75);
   			}

			if ((e.getType(dep) == 'D') && (e.getCouleur(dep) == 'N')) // reine noirs
   			{
   				spritePiece.setTexture(reine);
                spritePiece.setColor(sf::Color(0, 0, 0));
   				spritePiece.setPosition(x * 75, y * 75);
   			}

			if ((e.getType(dep) == 'R') && (e.getCouleur(dep) == 'N')) // roi noirs
            { 				
   				spritePiece.setTexture(roi);
                spritePiece.setColor(sf::Color(0, 0, 0));
  				spritePiece.setPosition(x * 75, y * 75);
   			}

   			if ((e.getType(dep) == 'P') && (e.getCouleur(dep) == 'N')) // pions noirs
   			{
   				spritePiece.setTexture(pion);
                spritePiece.setColor(sf::Color(0, 0, 0));
   				spritePiece.setPosition(x * 75, y * 75);
   			}

   			// Pieces blanches

   			if ((e.getType(dep) == 'T') && (e.getCouleur(dep) == 'B')) // tours blancs
   			{
   				spritePiece.setTexture(tour);
   				spritePiece.setColor(sf::Color(255, 255, 255));
   				spritePiece.setPosition(x * 75, y * 75);
   			}

			if ((e.getType(dep) == 'F') && (e.getCouleur(dep) == 'B')) // fous blancs
   			{
   				spritePiece.setTexture(fou);
   				spritePiece.setColor(sf::Color(255, 255, 255));
   				spritePiece.setPosition(x * 75, y * 75);
   			}

			if ((e.getType(dep) == 'C') && (e.getCouleur(dep) == 'B')) // cavaliers blancs
   			{
 				spritePiece.setTexture(cavalier);
   				spritePiece.setColor(sf::Color(255, 255, 255));
   				spritePiece.setPosition(x * 75, y * 75);
   			}

			if ((e.getType(dep) == 'D') && (e.getCouleur(dep) == 'B')) // reine blanche
   			{
   				spritePiece.setTexture(reine);
   				spritePiece.setColor(sf::Color(255, 255, 255));
				spritePiece.setPosition(x * 75, y * 75);
   			}

			if ((e.getType(dep) == 'R') && (e.getCouleur(dep) == 'B')) // roi blanche
			{
   				spritePiece.setTexture(roi);
   				spritePiece.setColor(sf::Color(255, 255, 255));
   				spritePiece.setPosition(x * 75, y * 75);
   			}

   			if ((e.getType(dep) == 'P') && (e.getCouleur(dep) == 'B')) // pions blancs
   			{
   				spritePiece.setTexture(pion);
   				spritePiece.setColor(sf::Color(255, 255, 255));
   				spritePiece.setPosition(x * 75, y * 75);
   			}	

   			app.draw(spritePiece);
   		}
   	}   
}