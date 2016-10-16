
#include "Reine.hpp"


Reine::Reine(int id, bool etat, char c) : Piece(id,etat,c) {
   mvmt_.push_back(new MouvementDiagonale(8));
   mvmt_.push_back(new MouvementVertical(8));
   mvmt_.push_back(new MouvementHorizontal(8));
}

Reine::~Reine() {}

char Reine::afficher() {
   return 'D';
}

bool Reine::moveTo(Coord dep, Coord but, Echiquier *e) {
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk) {
      mvmtOk = mvmt_[i]->isMoveOk(dep, but, e, posInitiale_);
      ++i;
   }
   return mvmtOk;
}

bool Reine::attaquer(Coord dep, Coord but, Echiquier *e) {
   return moveTo(dep,but,e);
}
