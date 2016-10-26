/**
 * @file Fou.hpp
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

class Fou : public Piece
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Fou(bool etat, char c);

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
		virtual bool moveTo(Coord dep, Coord but, Echiquier *e);

		virtual bool attaquer(Coord dep, Coord but, Echiquier *e);

};
