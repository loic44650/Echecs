
#include "Pion.hpp"


Pion::Pion(int id, bool etat, char c) : Piece(id,etat,c) {}

Pion::~Pion() {}

char Pion::afficher() {
   return 'P';
}

bool Pion::moveTo(Coord dep, Coord but, Echiquier *e) { return false; }
