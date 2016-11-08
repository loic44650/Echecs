
#include "Reine.hpp"


Reine::Reine( bool etat, char c) : Piece(etat,c) {
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
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk) {
      mvmtOk = mvmt_[i]->isAttackOk(dep, but, e, posInitiale_);
      ++i;
   }
   return mvmtOk;
}

std::vector<Coord> Reine::mouvementPossible(Coord dep, Echiquier *e) {
   std::vector<Coord> tousLesMouvements;
   std::vector<Coord> tmp;

   for(auto m : mvmt_) {
      tmp = m->mouvementPossible(dep, e, c_, posInitiale_);
      tousLesMouvements.insert(tousLesMouvements.end(), tmp.begin(), tmp.end());
   }

   return tousLesMouvements;
}
