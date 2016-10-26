/**
 * @file MouvementHDiagonale.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 07 oct. 2016
 * @brief Fichier header définissant la classe MouvementHDiagonale
**/


#pragma once

/**
 * @brief
 *
**/

#include "Mouvement.hpp"


class MouvementDiagonale : public Mouvement
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		MouvementDiagonale(int d);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~MouvementDiagonale();

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

		bool peutAllerEn(Coord &dep, Coord &but, Echiquier *e);

};
