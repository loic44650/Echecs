#include "FactoryPiece.hpp"

/**
 * @brief 		constructeur 
 * @entrées 	aucunes
 * @sorties 	aucunes
**/
FactoryPiece::FactoryPiece() {}

/**
 * @brief 		fonction créant un pointeur sur pièce	
 * @entrées 	une string indiquant quelle pièce doit être créée et un char indiquant dans le cas d'un pion sa direcion
 * @sorties 	retourne un pointeur sur pièce
**/
std::shared_ptr<Piece> FactoryPiece::creerPiece(std::string piece, char dir)
{
	if(piece == "roiN" ) return std::shared_ptr<Piece>(new Roi(true, 'N'));

	else if(piece == "roiB") return std::shared_ptr<Piece>(new Roi(true, 'B'));
	
	else if(piece == "reineN") return std::shared_ptr<Piece>(new Reine(true, 'N'));
	
	else if(piece == "reineB") return std::shared_ptr<Piece>(new Reine(true, 'B'));
	
	else if(piece == "fouN") return std::shared_ptr<Piece>(new Fou(true, 'N'));
	
	else if(piece == "fouB") return std::shared_ptr<Piece>(new Fou(true, 'B'));
	
	else if(piece == "cavalierN") return std::shared_ptr<Piece>(new Cavalier(true, 'N'));
	
	else if(piece == "cavalierB") return std::shared_ptr<Piece>(new Cavalier(true, 'B'));
	
	else if(piece == "tourN") return std::shared_ptr<Piece>(new Tour(true, 'N'));
	
	else if(piece == "tourB") return std::shared_ptr<Piece>(new Tour(true, 'B'));
	
	else if(piece == "pionN") return std::shared_ptr<Piece>(new Pion(true, 'N',dir));
	
	else if(piece == "pionB") return std::shared_ptr<Piece>(new Pion(true, 'B',dir));

	else return nullptr;
}