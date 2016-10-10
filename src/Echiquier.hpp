/**
 * @file Echiquier.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class
**/


/**
 * @brief
 *
**/

#ifndef Echiquier_HPP
#define Echiquier_HPP

#include <iostream>
#include <memory>
#include "Colormod.hpp"

class Piece;
class Pion;

class Echiquier
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/

		Echiquier();
		~Echiquier();
		bool estOccupee(int x, int y);
		void afficher();
		void count_ptr();

	private:
		std::shared_ptr<Piece> echiquier_[8][8];

};


#endif
