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


void Window::drawPlateauInitial(sf::RenderTarget& app)
{
	sf::Sprite spritePlateau;
    spritePlateau.setTexture(plateau);
    spritePlateau.setScale(75, 75);

    sf::Sprite spritePiece;
    spritePiece.setScale(0.5, 0.5);

    app.draw(spritePlateau);

    	for (int x = 0; x < 8; ++x)
    	{
    		for (int y = 0; y < 8; ++y)
    		{
    			if ( (x == 0 && y == 0) || (x == 7 && y == 0)) // tours noirs
    			{
    				spritePiece.setTexture(tour);
    				spritePiece.setColor(sf::Color(47, 47, 12));
    				spritePiece.setPosition(x * 75, y * 75);
    			}

    			if ( (x == 1 && y == 0) || (x == 6 && y == 0)) // fous noirs
    			{
    				spritePiece.setTexture(fou);
    				spritePiece.setColor(sf::Color(47, 47, 12));
    				spritePiece.setPosition(x * 75, y * 75);
    			}

   				if (( x == 2 && y == 0) || (x == 5 && y == 0)) // cavaliers noirs
    			{
    				spritePiece.setTexture(cavalier);
    				spritePiece.setColor(sf::Color(47, 47, 12));
    				spritePiece.setPosition(x * 75, y * 75);
    			}

   				if ( x == 3 && y == 0 ) // reine noirs
    			{
    				spritePiece.setTexture(reine);
    				spritePiece.setColor(sf::Color(47, 47, 12));
    				spritePiece.setPosition(x * 75, y * 75);
    			}

   				if ( x == 4 && y == 0 ) // roi noirs
  				{
    				spritePiece.setTexture(roi);
    				spritePiece.setColor(sf::Color(47, 47, 12));
    				spritePiece.setPosition(x * 75, y * 75);
    			}

    			if ( y == 1 ) // pions noirs
    			{
    				spritePiece.setTexture(pion);
    				spritePiece.setColor(sf::Color(47, 47, 12));
    				spritePiece.setPosition(x * 75, y * 75);
    			}

    			// Pieces blanches

    			if ( (x == 0 && y == 7) || (x == 7 && y == 7)) // tours blancs
    			{
    				spritePiece.setTexture(tour);
    				spritePiece.setColor(sf::Color(255, 255, 255));
    				spritePiece.setPosition(x * 75, y * 75);
    			}

   				if ( (x == 1 && y == 7) || (x == 6 && y == 7)) // fous blancs
    			{
    				spritePiece.setTexture(fou);
    				spritePiece.setColor(sf::Color(255, 255, 255));
    				spritePiece.setPosition(x * 75, y * 75);
    			}

   				if ( (x == 2 && y == 7) || (x == 5 && y == 7)) // cavaliers blancs
    			{
    				spritePiece.setTexture(cavalier);
    				spritePiece.setColor(sf::Color(255, 255, 255));
    				spritePiece.setPosition(x * 75, y * 75);
    			}

   				if ( x == 3 && y == 7 ) // reine blanche
    			{
    				spritePiece.setTexture(reine);
    				spritePiece.setColor(sf::Color(255, 255, 255));
					spritePiece.setPosition(x * 75, y * 75);
    			}

   				if ( x == 4 && y == 7 ) // roi blanche
  				{
    				spritePiece.setTexture(roi);
    				spritePiece.setColor(sf::Color(255, 255, 255));
    				spritePiece.setPosition(x * 75, y * 75);
    			}

    			if ( y == 6 ) // pions blancs
    			{
    				spritePiece.setTexture(pion);
    				spritePiece.setColor(sf::Color(255, 255, 255));
    				spritePiece.setPosition(x * 75, y * 75);
    			}	
    			app.draw(spritePiece);
    		}
    	}   
}