#include "FactoryPiece.hpp"

FactoryPiece::FactoryPiece() {}

std::unique_ptr<Piece> FactoryPiece::creerPiece(std::string piece, char dir)
{
	if(piece == "roiN" ) return std::unique_ptr<Piece>(new Roi(true, 'N'));
	else if(piece == "roiB") return std::unique_ptr<Piece>(new Roi(true, 'B'));
	else if(piece == "reineN") return std::unique_ptr<Piece>(new Reine(true, 'N'));
	else if(piece == "reineB") return std::unique_ptr<Piece>(new Reine(true, 'B'));
	else if(piece == "fouN") return std::unique_ptr<Piece>(new Fou(true, 'N'));
	else if(piece == "fouB") return std::unique_ptr<Piece>(new Fou(true, 'B'));
	else if(piece == "cavalierN") return std::unique_ptr<Piece>(new Cavalier(true, 'N'));
	else if(piece == "cavalierB") return std::unique_ptr<Piece>(new Cavalier(true, 'B'));
	else if(piece == "tourN") return std::unique_ptr<Piece>(new Tour(true, 'N'));
	else if(piece == "tourB") return std::unique_ptr<Piece>(new Tour(true, 'B'));
	else if(piece == "pionN") return std::unique_ptr<Piece>(new Pion(true, 'N',dir));
	else if(piece == "pionB") return std::unique_ptr<Piece>(new Pion(true, 'B',dir));
}
