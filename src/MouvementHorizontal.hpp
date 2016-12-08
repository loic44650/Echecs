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
		 * @entrées    
		 * @sorties    
		**/
		MouvementHorizontal(int d);

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		~MouvementHorizontal();

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