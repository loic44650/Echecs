/**
 * @file Echiquier.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class
**/

#pragma once

#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <vector>
#include "Colormod.hpp"
#include "utils.hpp"

class Piece;
class FactoryPiece;

class Echiquier
{
	public:
		
		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		Echiquier();

		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		Echiquier(const std::string &);
		
		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		~Echiquier();
		
		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		void setEchiquier(const std::string &);
		
		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		bool estOccupee(Coord);
		
		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		int getTypeMouvement(Coord, Coord );

		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		bool pieceEnPosInit(int, int);
		
		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		char getType(Coord);
		
		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		char getCouleur(Coord);

		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		void afficher();
		
		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/	
		bool move(Coord, Coord);
		
		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/	
		void movePiece(Coord, Coord);
		
		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		void mangerPiece(Coord, Coord);
		
		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		bool estEchec(Coord);
		
		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		bool estMat(Coord);
		
		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		Coord findPiece(char, char);
		
		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/	
		std::vector<Coord> mouvementPossible(Coord);

		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		void annulerCoup(Coord, Coord);

	private:
		
		std::shared_ptr<Piece> echiquier_[8][8];
		std::shared_ptr<Piece> dernierePieceMangee_;
		Coord pieceAttaquante_;
};