
#include "Cavalier.hpp"


Cavalier::Cavalier(int id, bool etat, char c) : Piece(id,etat,c) {}

Cavalier::~Cavalier() {}

char Cavalier::afficher() {
   return 'C';
}

bool Cavalier::moveTo(Coord dep, Coord but, Echiquier *e) {
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk) {
      mvmtOk = mvmt_[i]->isMoveOk(dep, but, e);
      ++i;
   }
   return mvmtOk;
}
