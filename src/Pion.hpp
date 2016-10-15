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


class Pion: public Piece
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Pion(int, bool, char, char);

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
		char afficher();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		virtual bool moveTo(Coord dep, Coord but, Echiquier *e);


};

#endif
