
#include "Tour.hpp"
#include <iostream>

Tour::Tour(int id, bool etat, char c) : Piece(id,etat,c) {
   mvmt_.push_back(new MouvementHorizontal(8,false));
   mvmt_.push_back(new MouvementVertical(8,false));
}

Tour::~Tour() {}

char Tour::afficher() {
   return 'T';
}

bool Tour::moveTo(Coord dep, Coord but, Echiquier *e) {
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk) {
      mvmtOk = mvmt_[i]->isMoveOk(dep, but, e);
      ++i;
   }

   return mvmtOk;
}
