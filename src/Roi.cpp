
#include "Roi.hpp"


Roi::Roi(bool etat, char c) : Piece(etat,c) {
   mvmt_.push_back(new MouvementDiagonale(1));
   mvmt_.push_back(new MouvementVertical(1));
   mvmt_.push_back(new MouvementHorizontal(1));
<<<<<<< HEAD
   roque_ = std::unique_ptr<Mouvement>(new MouvementRock(5));
=======
   roque_ = std::unique_ptr<Mouvement>(new MouvementRoque(4));
>>>>>>> factory
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

bool Roi::roque(Coord dep, Coord but, Echiquier *e) {
   return roque_->isMoveOk(dep,but,e,posInitiale_);
}
