
#include "Pion.hpp"


Pion::Pion(bool etat, char c, char dir) : Piece(etat,c) {
   mvmt_.push_back(new MouvementPion(1,dir));
}

Pion::~Pion() {}

char Pion::afficher() {
   return 'P';
}

bool Pion::moveTo(Coord dep, Coord but, Echiquier *e) {
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk) {
      mvmtOk = mvmt_[i]->isMoveOk(dep, but, e, posInitiale_);
      ++i;
   }
   if(mvmtOk) posInitiale_ = false;
   return mvmtOk;
}

bool Pion::attaquer(Coord dep, Coord but, Echiquier *e) {
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk) {
      mvmtOk = mvmt_[i]->isAttackOk(dep, but, e,posInitiale_);
      ++i;
   }
   if(mvmtOk) posInitiale_ = false;
   return mvmtOk;
}
