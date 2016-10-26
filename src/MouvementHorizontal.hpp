/**
 * @file MouvementHorizontal.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 07 oct. 2016
 * @brief Fichier header définissant la classe MouvementHorizontal
**/


#pragma once

#include "Mouvement.hpp"
class Echiquier;

class MouvementHorizontal : public Mouvement
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		MouvementHorizontal(int d);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~MouvementHorizontal();

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
