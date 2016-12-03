/**
 * @file Mouvement.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 07 oct. 2016
 * @brief Fichier header définissant la classe Mouvement
**/

#pragma once

#include <vector>
#include "utils.hpp" // contient struct Coord
#include "Echiquier.hpp"

class Mouvement
{
	public:

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Mouvement(int d);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~Mouvement();

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
		virtual bool makeMove(Coord &dep, Coord &but, Echiquier *e, bool posInit) = 0;

		virtual bool makeAttack(Coord &dep, Coord &but, Echiquier *e, bool posInit) = 0;

		virtual std::vector<Coord> mouvementPossible(Coord dep, Echiquier *e, char col, bool posInit) = 0;

   protected:

      int distance_;
};