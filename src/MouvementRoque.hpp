/**
 * @file MouvementRoque.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 07 oct. 2016
 * @brief Fichier header définissant la classe MouvementRoque
**/

#pragma once

#include "Mouvement.hpp"

class MouvementRoque : public Mouvement
{
	public:

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		MouvementRoque(int d);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~MouvementRoque();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		virtual bool makeMove(Coord &dep, Coord &but, Echiquier *e, bool posInit);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		virtual bool makeAttack(Coord &dep, Coord &but, Echiquier *e, bool posInit);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		virtual std::vector<Coord> mouvementPossible(Coord dep, Echiquier *e, char col, bool posInit);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		bool isMoveOk(Coord &but, Coord& coordRoi, Coord& coordTour, Echiquier *e, bool posInit);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		void setPositionsFinales(Coord &coordRoi, Coord &coordTour);
};