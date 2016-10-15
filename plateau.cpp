#include <cstdlib>
#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "Echecs", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);


    sf::Texture pion;
    sf::Texture tour;
    sf::Texture fou;
    sf::Texture cavalier;
    sf::Texture reine;
    sf::Texture roi;
    sf::Texture plateau;
    
    pion.loadFromFile("picture/pion.png");
    tour.loadFromFile("picture/tour.png");
    fou.loadFromFile("picture/fou.png");
    cavalier.loadFromFile("picture/cavalier.png");
    reine.loadFromFile("picture/reine.png");
    roi.loadFromFile("picture/roi.png");
    plateau.loadFromFile("picture/plateau.png");


    sf::Sprite spritePlateau;
    spritePlateau.setTexture(plateau);
    spritePlateau.setScale(75, 75);

    sf::Sprite spritePiece;
    spritePiece.setScale(0.5, 0.5);


//---------------------------------------------------

    while (app.isOpen())
    {
        sf::Event event;

        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();
        }

        app.clear(sf::Color(187, 174, 152));
    	app.draw(spritePlateau);
    	for (int x = 0; x < 8; ++x)
    	{
    		for (int y = 0; y < 8; ++y)
    		{
    			if ( x == 0 && y == 0 || x == 7 && y == 0) // tours noirs
    			{
    				spritePiece.setTexture(tour);
    				spritePiece.setColor(sf::Color(47, 47, 12));
    				spritePiece.setPosition(x * 75, y * 75);
    				app.draw(spritePiece);    				
    			}

    			if ( x == 1 && y == 0 || x == 6 && y == 0) // fous noirs
    			{
    				spritePiece.setTexture(fou);
    				spritePiece.setColor(sf::Color(47, 47, 12));
    				spritePiece.setPosition(x * 75, y * 75);
    				app.draw(spritePiece);    				
    			}

   				if ( x == 2 && y == 0 || x == 5 && y == 0) // cavaliers noirs
    			{
    				spritePiece.setTexture(cavalier);
    				spritePiece.setColor(sf::Color(47, 47, 12));
    				spritePiece.setPosition(x * 75, y * 75);
    				app.draw(spritePiece);    				
    			}

   				if ( x == 3 && y == 0 ) // reine noirs
    			{
    				spritePiece.setTexture(reine);
    				spritePiece.setColor(sf::Color(47, 47, 12));
    				spritePiece.setPosition(x * 75, y * 75);
    				app.draw(spritePiece);    				
    			}

   				if ( x == 4 && y == 0 ) // roi noirs
  				{
    				spritePiece.setTexture(roi);
    				spritePiece.setColor(sf::Color(47, 47, 12));
    				spritePiece.setPosition(x * 75, y * 75);
    				app.draw(spritePiece);    				
    			}

    			if ( y == 1 ) // pions noirs
    			{
    				spritePiece.setTexture(pion);
    				spritePiece.setColor(sf::Color(47, 47, 12));
    				spritePiece.setPosition(x * 75, y * 75);
    				app.draw(spritePiece);
    			}

    			// Pieces blanches

    			if ( x == 0 && y == 7 || x == 7 && y == 7) // tours blancs
    			{
    				spritePiece.setTexture(tour);
    				spritePiece.setColor(sf::Color(255, 255, 255));
    				spritePiece.setPosition(x * 75, y * 75);
    				app.draw(spritePiece);    				
    			}

   				if ( x == 1 && y == 7 || x == 6 && y == 7) // fous blancs
    			{
    				spritePiece.setTexture(fou);
    				spritePiece.setColor(sf::Color(255, 255, 255));
    				spritePiece.setPosition(x * 75, y * 75);
    				app.draw(spritePiece);    				
    			}

   				if ( x == 2 && y == 7 || x == 5 && y == 7) // cavaliers blancs
    			{
    				spritePiece.setTexture(cavalier);
    				spritePiece.setColor(sf::Color(255, 255, 255));
    				spritePiece.setPosition(x * 75, y * 75);
    				app.draw(spritePiece);    				
    			}

   				if ( x == 3 && y == 7 ) // reine blanche
    			{
    				spritePiece.setTexture(reine);
    				spritePiece.setColor(sf::Color(255, 255, 255));
					spritePiece.setPosition(x * 75, y * 75);
    				app.draw(spritePiece);    				
    			}

   				if ( x == 4 && y == 7 ) // roi blanche
  				{
    				spritePiece.setTexture(roi);
    				spritePiece.setColor(sf::Color(255, 255, 255));
    				spritePiece.setPosition(x * 75, y * 75);
    				app.draw(spritePiece);    				
    			}

    			if ( y == 6 ) // pions blancs
    			{
    				spritePiece.setTexture(pion);
    				spritePiece.setColor(sf::Color(255, 255, 255));
    				spritePiece.setPosition(x * 75, y * 75);
    				app.draw(spritePiece);
    			}	
    		}
    	}    	
        app.display();
    }

    return 0;
}