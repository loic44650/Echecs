#include "FactoryPiece.hpp"

FactoryPiece::FactoryPiece() {}

FactoryPiece::creerPiece(string piece, char dir)
{
	switch (piece)
	{
		case 'roiN':	std::unique_ptr<Piece>(new Roi(true, 'N'));

		case 'roiB':	std::unique_ptr<Piece>(new Roi(true, 'B'));
		
		case 'reineN':	std::unique_ptr<Piece>(new Reine(true, 'N'));
		
		case 'reineB':	std::unique_ptr<Piece>(new Reine(true, 'B'));
		
		case 'FouN':	std::unique_ptr<Piece>(new Fou(true, 'N'));
		
		case 'FouB':	std::unique_ptr<Piece>(new Fou(true, 'B'));
		
		case 'cavalierN':	std::unique_ptr<Piece>(new Cavalier(true, 'N'));
		
		case 'cavalierB':	std::unique_ptr<Piece>(new Cavalier(true, 'B'));
		
		case 'tourN':	std::unique_ptr<Piece>(new Tour(true, 'N'));
		
		case 'tourB':	std::unique_ptr<Piece>(new Tour(true, 'B'));   
		
		case 'pionN':	if (dir == 'S' || dir == 'N') std::unique_ptr<Piece>(new Pion(true, 'N', dir));

		case 'pionB':	if (dir == 'S' || dir == 'N') std::unique_ptr<Piece>(new Pion(true, 'B', dir));
	}
}

FactoryPiece::~FactoryPiece() {}