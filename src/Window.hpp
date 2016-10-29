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

#pragma once

#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "Echiquier.hpp"


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
		~Window();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		void drawPlateau(sf::RenderTarget& app, Echiquier& e);


	private:
    sf::Texture plateau;
	sf::Texture pion;
    sf::Texture tour;
    sf::Texture fou;
    sf::Texture cavalier;
    sf::Texture reine;
    sf::Texture roi;

};
