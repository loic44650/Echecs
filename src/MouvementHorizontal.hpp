/**
 * @file MouvementHorizontal.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 07 oct. 2016
 * @brief Fichier header définissant la classe MouvementHorizontal
**/


#ifndef MouvementHorizontal_HPP
#define MouvementHorizontal_HPP

/**
 * @brief
 *
**/

#include "Mouvement.hpp"


class MouvementHorizontal : public Mouvement
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		MouvementHorizontal(int d, bool saut);

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
		virtual std::vector<Coord> deplacement(Coord &dep, Echiquier &e);


};

#endif
