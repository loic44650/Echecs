#include "Fou.hpp"


Fou::Fou( bool etat, char c) : Piece(etat,c) {
   mvmt_.push_back(new MouvementDiagonale(8));
}

Fou::~Fou() {}

char Fou::afficher() {
   return 'F';
}


bool Fou::moveTo(Coord dep, Coord but, Echiquier *e) {
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk) {
      mvmtOk = mvmt_[i]->isMoveOk(dep, but, e, posInitiale_);
      ++i;
   }
   return mvmtOk;
}

bool Fou::attaquer(Coord dep, Coord but, Echiquier *e) {
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk) {
      mvmtOk = mvmt_[i]->isAttackOk(dep, but, e, posInitiale_);
      ++i;
   }
   return mvmtOk;
}

std::vector<Coord> Fou::mouvementPossible(Coord dep, Echiquier *e) {
   std::vector<Coord> tousLesMouvements;
   std::vector<Coord> tmp;

   for(auto m : mvmt_) {
      tmp = m->mouvementPossible(dep, e, c_, posInitiale_);
      tousLesMouvements.insert(tousLesMouvements.end(), tmp.begin(), tmp.end());
   }

   return tousLesMouvements;
}
