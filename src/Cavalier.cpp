
#include "Cavalier.hpp"


Cavalier::Cavalier(bool etat, char c) : Piece(etat,c) {
   mvmt_.push_back(new MouvementCavalier(8));
}

Cavalier::~Cavalier() {}

char Cavalier::afficher() {
   return 'C';
}

bool Cavalier::moveTo(Coord dep, Coord but, Echiquier *e) {
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk) {
      mvmtOk = mvmt_[i]->isMoveOk(dep, but, e, posInitiale_);
      ++i;
   }
   return mvmtOk;
}

bool Cavalier::attaquer(Coord dep, Coord but, Echiquier *e) {
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk) {
      mvmtOk = mvmt_[i]->isAttackOk(dep, but, e, posInitiale_);
      ++i;
   }
   return mvmtOk;
}
