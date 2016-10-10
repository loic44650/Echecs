/**
 * @file Tour.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant la classe Tour
**/


#ifndef TOUR_HPP
#define TOUR_HPP

/**
 * @brief
 *
**/

#include "Piece.hpp"

class Tour : public Piece
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Tour(int id, bool etat, char c);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~Tour();

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
