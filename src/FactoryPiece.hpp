/**
 * @file FactoryPiece.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class FactoryPiece gérant les différentes FactoryPieces de l'échiquier
**/

#ifndef FactoryPiece_HPP
#define FactoryPiece_HPP

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
		creerPiece(string piece, char dir);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~FactoryPiece();

};

#endif
