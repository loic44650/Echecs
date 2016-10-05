/**
 * @file Cavalier.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class
**/

#ifndef CAVALIER_HPP
#define CAVALIER_HPP

/**
 * @brief
 *
**/

#include "Piece.hpp"
#include <iostream>

class Cavalier : public Piece
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Cavalier(int id, bool etat, char c);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~Cavalier();

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
