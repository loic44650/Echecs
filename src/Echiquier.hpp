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

		Echiquier(const std::string &nomFichier);
		~Echiquier();
		bool estOccupee(Coord coord);
		int getTypeMouvement(Coord dep,Coord but);
		bool pieceEnPosInit(int x, int y);
		char getType(Coord c);
		void afficher();
		bool move(Coord dep, Coord but);
		void movePiece(Coord deb, Coord but);
		void mangerPiece(Coord deb, Coord but);
		bool estEchec(Coord roi);
		bool estMat(Coord roi);

	private:
		std::shared_ptr<Piece> echiquier_[8][8];

};
