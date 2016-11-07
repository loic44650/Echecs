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

#pragma once

#include "Piece.hpp"


class Pion: public Piece
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Pion(bool, char, char);

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

		virtual bool attaquer(Coord dep, Coord but, Echiquier *e);

		virtual std::vector<Coord> mouvementPossible(Coord dep, Echiquier *e);

};
