/**
 * @file Reine.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class
**/


#pragma once

/**
 * @brief
 *
**/

#include "Piece.hpp"

class Reine : public Piece
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Reine(bool etat, char c);

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
