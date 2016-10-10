/**
 * @file Piece.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class piece gérant les différentes pieces de l'échiquier
**/


/**
 * @brief
 *
**/

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <cstdlib>
#include <SFML/Graphics.hpp>


class Window
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Window();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		void drawPlateauInitial(sf::RenderTarget& app);


	private:
    sf::Texture plateau;
	sf::Texture pion;
    sf::Texture tour;
    sf::Texture fou;
    sf::Texture cavalier;
    sf::Texture reine;
    sf::Texture roi;

};

#endif
