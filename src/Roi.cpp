
#include "Roi.hpp"


Roi::Roi(int id, bool etat, char c) : Piece(id,etat,c), echec_(false), echecEtMat_(false) {}

Roi::~Roi() {}

char Roi::afficher() {
   return 'K';
}

void Roi::deplacement(Coord &c, Echiquier &e) {}
