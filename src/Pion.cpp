
#include "Pion.hpp"


Pion::Pion(int id, bool etat, char c) : Piece(id,etat,c) {}

Pion::~Pion() {}

char Pion::afficher() {
   return 'P';
}

bool Pion::moveTo(Coord dep, Coord but, Echiquier *e) {
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk) {
      mvmtOk = mvmt_[i]->isMoveOk(dep, but, e);
      ++i;
   }
   return mvmtOk;
}
