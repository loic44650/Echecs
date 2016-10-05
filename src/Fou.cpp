
#include "Fou.hpp"


Fou::Fou(int id, bool etat, char c) : Piece(id,etat,c) {}

Fou::~Fou() {}

void Fou::afficher() {
   std::cout << "F|";
}
