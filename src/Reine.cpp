
#include "Reine.hpp"


Reine::Reine(int id, bool etat, char c) : Piece(id,etat,c) {}

Reine::~Reine() {}

char Reine::afficher() {
   return 'R';
}

void Reine::deplacement(Coord &c, Echiquier &e) {}
