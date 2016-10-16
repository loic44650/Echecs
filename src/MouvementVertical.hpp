/**
 * @file MouvementVertical.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 07 oct. 2016
 * @brief Fichier header définissant la classe MouvementVertical
**/


#ifndef MouvementVertical_HPP
#define MouvementVertical_HPP

/**
 * @brief
 *
**/

#include "Mouvement.hpp"


class MouvementVertical : public Mouvement
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		MouvementVertical(int d);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~MouvementVertical();

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
