/**
 * @file FactoryPiece.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class FactoryPiece gérant les différentes FactoryPieces de l'échiquier
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
 		 * @brief
 		 *
 		 * @complexité
		**/
		FactoryPiece();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		std::unique_ptr<Piece> creerPiece(std::string piece, char dir);


};
