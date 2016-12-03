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
		bool peutAllerEn(Coord &dep, Coord &but, Echiquier *e);
};