/**
 * @file MouvementPion.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 07 oct. 2016
 * @brief Fichier header définissant la classe MouvementPion
**/

#pragma once

#include "Mouvement.hpp"

class MouvementPion : public Mouvement
{
	public:

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		MouvementPion(int, char);

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		~MouvementPion();

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		virtual bool makeMove(Coord &, Coord &, Echiquier *, bool , std::vector<Coord>&);

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
		bool peutAllerEn(Coord &, Coord &, Echiquier *, bool);

   	private:

    	char direction_;
};