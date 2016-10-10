#include <iostream>
#include "Echiquier.hpp"
#include "Piece.hpp"


using namespace std;


int main()
{
	Echiquier e;
	e.afficher();
	Coord c;
	c.x = 3; c.y = 4;
	e.selectPiece(3,4)->deplacement(c, e);

}
