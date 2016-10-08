
#include "Pion.hpp"


Pion::Pion(int id, bool etat, char c) : Piece(id,etat,c) {}

Pion::~Pion() {}

char Pion::afficher() {
   return 'P';
}

void Pion::deplacement(Coord &c, Echiquier &e) {

}
