/**
 * @file Pion.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class
**/


/**
 * @brief
 *
**/

#ifndef PION_HPP
#define PION_HPP

#include "Piece.hpp"
#include <iostream>

class Pion: public Piece
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Pion(int, bool, char);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~Pion();

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
