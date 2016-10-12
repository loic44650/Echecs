#include <iostream>
#include "Echiquier.hpp"
#include "Piece.hpp"


using namespace std;


int main()
{
	Echiquier e;
	e.afficher();
	Coord dep, but;
	cout << "Selectionne la pièce à déplacer : ";
	cin >> dep.x >> dep.y;
	cout << "Sélectionne la case d'arrivée : ";
	cin >> but.x >> but.y;
	e.move(dep,but);
	e.afficher();
}
