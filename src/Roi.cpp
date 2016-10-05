
#include "Roi.hpp"


Roi::Roi(int id, bool etat, char c) : Piece(id,etat,c), echec_(false), echecEtMat_(false) {}

Roi::~Roi() {}

void Roi::afficher() {
   std::cout << "K|";
}
