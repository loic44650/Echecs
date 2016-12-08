/**
 * @file MouvementVertical.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 07 oct. 2016
 * @brief Fichier header définissant la classe MouvementVertical
**/

#pragma once

#include "Mouvement.hpp"

class MouvementVertical : public Mouvement
{
	public:

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		MouvementVertical(int);

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		~MouvementVertical();

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		virtual bool makeMove(Coord &, Coord &, Echiquier *, bool, std::vector<Coord>&);

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		virtual bool makeAttack(Coord &, Coord &, Echiquier *, bool, std::vector<Coord>&);

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		virtual std::vector<Coord> mouvementPossible(Coord, Echiquier *, char, bool);

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		bool peutAllerEn(Coord &, Coord &, Echiquier *, std::vector<Coord>&);
};