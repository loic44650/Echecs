
/**
 * @file MouvementPion.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 07 oct. 2016
 * @brief Fichier header définissant la classe MouvementPion
**/


#pragma once

/**
 * @brief
 *
**/

#include "Mouvement.hpp"


class MouvementPion : public Mouvement
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		MouvementPion(int d, char dir);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~MouvementPion();

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

		bool peutAllerEn(Coord &dep, Coord &but, Echiquier *e, bool posInit);

   private:
      char direction_;

};
