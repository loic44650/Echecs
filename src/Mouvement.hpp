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
		 * @entrées    
		 * @sorties    
		**/
		Mouvement(int);

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		~Mouvement();

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		virtual bool makeMove(Coord &, Coord &, Echiquier *, bool, std::vector<Coord>&) = 0;

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		virtual bool makeAttack(Coord &, Coord &, Echiquier *, bool, std::vector<Coord>&) = 0;

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		virtual std::vector<Coord> mouvementPossible(Coord, Echiquier *, char, bool) = 0;

   protected:

      int distance_;
};