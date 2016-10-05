
#include "Tour.hpp"


Tour::Tour(int id, bool etat, char c) : Piece(id,etat,c) {}

Tour::~Tour() {}

char Tour::afficher() {
   return 'T';
}
