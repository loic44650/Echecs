
#include "Roi.hpp"


Roi::Roi(bool etat, char c) : Piece(etat,c) {
   mvmt_.push_back(new MouvementDiagonale(1));
   mvmt_.push_back(new MouvementVertical(1));
   mvmt_.push_back(new MouvementHorizontal(1));

   roque_ = std::unique_ptr<Mouvement>(new MouvementRoque(4));
}

Roi::~Roi() {}

char Roi::afficher() {
   return 'R';
}

bool Roi::moveTo(Coord dep, Coord but, Echiquier *e) {
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk) {
      std::cout << "Im Roi::moveTo\n";
      mvmtOk = mvmt_[i]->isMoveOk(dep, but, e, posInitiale_);
      ++i;
   }

   return mvmtOk;
}

bool Roi::attaquer(Coord dep, Coord but, Echiquier *e) {
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk) {
      mvmtOk = mvmt_[i]->isAttackOk(dep, but, e, posInitiale_);
      ++i;
   }
   return mvmtOk;
}


bool Roi::roquer(Coord dep, Coord but, Echiquier *e) {
   return roque_->isMoveOk(dep,but,e,posInitiale_);
}


std::vector<Coord> Roi::mouvementPossible(Coord dep, Echiquier *e) {
   std::vector<Coord> tousLesMouvements;
   std::vector<Coord> tmp;

   for(auto m : mvmt_) {
      tmp = m->mouvementPossible(dep, e, c_, posInitiale_);
      tousLesMouvements.insert(tousLesMouvements.end(), tmp.begin(), tmp.end());
   }

   tmp = roque_->mouvementPossible(dep, e, c_, posInitiale_);
   tousLesMouvements.insert(tousLesMouvements.end(), tmp.begin(), tmp.end());

   return tousLesMouvements;
}
