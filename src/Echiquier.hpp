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
 		 *
 		 * @complexité
		**/
		Echiquier();

		Echiquier(const std::string &nomFichier);
		
		~Echiquier();
		
		void setEchiquier(const std::string &nomFichier);
		
		bool estOccupee(Coord coord);
		
		int getTypeMouvement(Coord dep,Coord but);
		
		bool pieceEnPosInit(int x, int y);
		
		char getType(Coord c);
		
		char getCouleur(Coord c);
		
		void afficher();
		
		bool move(Coord dep, Coord but);
		
		void movePiece(Coord deb, Coord but);
		
		void mangerPiece(Coord deb, Coord but);
		
		bool estEchec(Coord roi);
		
		bool estMat(Coord roi);
		
		Coord findPiece(char piece, char coul);
		
		std::vector<Coord> mouvementPossible(Coord dep);

		void annulerCoup(Coord, Coord);

	private:
		
		std::unique_ptr<Piece> echiquier_[8][8];
		std::unique_ptr<Piece> dernierePieceMangee_;
};