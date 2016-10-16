/**
 * @file MouvementCavalier.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 07 oct. 2016
 * @brief Fichier header définissant la classe MouvementCavalier
**/


#ifndef MouvementCavalier_HPP
#define MouvementCavalier_HPP

/**
 * @brief
 *
**/

#include "Mouvement.hpp"


class MouvementCavalier : public Mouvement
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		MouvementCavalier(int d);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~MouvementCavalier();

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
		virtual bool isMoveOk(Coord &dep, Coord &but, Echiquier *e);

		virtual bool isAttackOk(Coord &dep, Coord &but, Echiquier *e);

};

#endif
