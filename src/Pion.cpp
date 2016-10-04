
#include "Pion.hpp"


Pion::Pion(int id, bool etat, char c) : Piece(id,etat,c) {}

Pion::~Pion() {}

void Pion::afficher() {
   std::cout << "P|";
}
