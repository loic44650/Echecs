
#include "Reine.hpp"


Reine::Reine(int id, bool etat, char c) : Piece(id,etat,c) {}

Reine::~Reine() {}

void Reine::afficher() {
   std::cout << "R|";
}
