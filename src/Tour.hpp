/**
 * @file Tour.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant la classe Tour
**/


#pragma once

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
		Tour(bool etat, char c);

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

		virtual bool moveTo(Coord dep, Coord but, Echiquier *e);

		virtual bool attaquer(Coord dep, Coord but, Echiquier *e);

		bool roquer(Coord dep, Coord but, Echiquier *e);


	private:

		std::unique_ptr<Mouvement> roque_;
};
