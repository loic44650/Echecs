/**
 * @file MouvementHDiagonale.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 07 oct. 2016
 * @brief Fichier header définissant la classe MouvementHDiagonale
**/

#pragma once

#include "Mouvement.hpp"

class MouvementDiagonale : public Mouvement
{
	public:

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		MouvementDiagonale(int);

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		~MouvementDiagonale();
		
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