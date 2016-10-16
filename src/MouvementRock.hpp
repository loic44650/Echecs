/**
 * @file MouvementRock.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 07 oct. 2016
 * @brief Fichier header définissant la classe MouvementRock
**/


#ifndef MouvementRock_HPP
#define MouvementRock_HPP

/**
 * @brief
 *
**/

#include "Mouvement.hpp"


class MouvementRock : public Mouvement
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		MouvementRock(int d);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~MouvementRock();

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

};

#endif
