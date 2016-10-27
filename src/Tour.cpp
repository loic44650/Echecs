
#include "Tour.hpp"
#include <iostream>

Tour::Tour(bool etat, char c) : Piece(etat,c) {
   mvmt_.push_back(new MouvementHorizontal(8));
   mvmt_.push_back(new MouvementVertical(8));
   roque_ = std::unique_ptr<Mouvement>(new MouvementRoque(4));
}

Tour::~Tour() {}

char Tour::afficher() {
   return 'T';
}

bool Tour::moveTo(Coord dep, Coord but, Echiquier *e) {
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk) {
      mvmtOk = mvmt_[i]->isMoveOk(dep, but, e, posInitiale_);
      ++i;
   }

   return mvmtOk;
}


bool Tour::attaquer(Coord dep, Coord but, Echiquier *e) {
   return moveTo(dep,but,e);
}


bool Tour::roquer(Coord dep, Coord but, Echiquier *e) {
   return roque_->isMoveOk(dep,but,e,posInitiale_);
}
