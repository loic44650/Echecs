/**
 * @file Reine.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class
**/


#ifndef REINE_HPP
#define REINE_HPP

/**
 * @brief
 *
**/

#include "Piece.hpp"
#include <iostream>

class Reine : public Piece
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Reine(int id, bool etat, char c);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~Reine();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		void afficher();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		//void deplacement(Echiquier plateau);



};

#endif
