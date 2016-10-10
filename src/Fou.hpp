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
		char afficher();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		void deplacement(Coord &c, Echiquier &e);



};

#endif
