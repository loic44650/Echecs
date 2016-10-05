
#include "Cavalier.hpp"


Cavalier::Cavalier(int id, bool etat, char c) : Piece(id,etat,c) {}

Cavalier::~Cavalier() {}

void Cavalier::afficher() {
   std::cout << "C|";
}
