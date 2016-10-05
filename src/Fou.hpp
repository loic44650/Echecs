/**
 * @file Fou.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class
**/

#ifndef FOU_HPP
#define FOU_HPP

/**
 * @brief
 *
**/

#include "Piece.hpp"
#include <iostream>

class Fou : public Piece
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Fou(int id, bool etat, char c);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~Fou();

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
