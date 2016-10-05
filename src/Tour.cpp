
#include "Tour.hpp"


Tour::Tour(int id, bool etat, char c) : Piece(id,etat,c) {}

Tour::~Tour() {}

void Tour::afficher() {
   std::cout << "T|";
}
