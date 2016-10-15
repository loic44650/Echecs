
#include "Reine.hpp"


Reine::Reine(int id, bool etat, char c) : Piece(id,etat,c) {}

Reine::~Reine() {}

char Reine::afficher() {
   return 'R';
}

bool Reine::moveTo(Coord dep, Coord but, Echiquier *e){ return false; }
