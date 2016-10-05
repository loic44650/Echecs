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
#include "Piece.hpp"
#include "Pion.hpp"
#include "Colormod.hpp"


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
		void afficher();
		void count_ptr();

	private:
		std::shared_ptr<Piece> echiquier_[8][8];

};


#endif
