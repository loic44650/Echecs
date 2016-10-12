
#include "Cavalier.hpp"


Cavalier::Cavalier(int id, bool etat, char c) : Piece(id,etat,c) {}

Cavalier::~Cavalier() {}

char Cavalier::afficher() {
   return 'C';
}

bool Cavalier::moveTo(Coord dep, Coord but, Echiquier *e) { return false; }
