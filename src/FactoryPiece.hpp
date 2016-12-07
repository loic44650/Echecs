/**
 * @file FactoryPiece.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une classe FactoryPiece créant les différentes pièces concrètes
**/

#pragma once

#include <memory>
#include "Piece.hpp"
#include "Roi.hpp"
#include "Reine.hpp"
#include "Fou.hpp"
#include "Cavalier.hpp"
#include "Tour.hpp"
#include "Pion.hpp"


class FactoryPiece
{
	public:

		/**
 		 * @brief 		constructeur 
 		 * @entrées 	aucunes
 		 * @sorties 	aucunes
		**/
		FactoryPiece();

		/**
 		 * @brief 		fonction créant un pointeur sur pièce	
 		 * @entrées 	une string indiquant quelle pièce doit être créée et un char indiquant dans le cas d'un pion sa direcion
 		 * @sorties 	retourne un pointeur sur pièce
		**/
		std::shared_ptr<Piece> creerPiece(std::string piece, char dir);
};