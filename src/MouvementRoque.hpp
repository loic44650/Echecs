/**
 * @file MouvementRoque.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 07 oct. 2016
 * @brief Fichier header définissant la classe MouvementRoque
**/

#pragma once

#include "Mouvement.hpp"

class MouvementRoque : public Mouvement
{
	public:

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		MouvementRoque(int);

		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		~MouvementRoque();

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
		bool isMoveOk(Coord &, Coord&, Coord&, Echiquier *, bool);
		
		/**
		 * @brief       
		 * @entrées    
		 * @sorties    
		**/
		void setPositionsFinales(Coord &, Coord &);
};