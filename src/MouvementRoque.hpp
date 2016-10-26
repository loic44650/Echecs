/**
 * @file MouvementRoque.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 07 oct. 2016
 * @brief Fichier header définissant la classe MouvementRoque
**/


#pragma once

/**
 * @brief
 *
**/

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


		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		virtual bool isMoveOk(Coord &dep, Coord &but, Echiquier *e, bool posInit);

		virtual bool isAttackOk(Coord &dep, Coord &but, Echiquier *e, bool posInit);

		void setPositionsFinales(Coord &coordRoi, Coord &coordTour);

};
