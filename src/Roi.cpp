
#include "Roi.hpp"


Roi::Roi(int id, bool etat, char c) : Piece(id,etat,c), echec_(false), echecEtMat_(false) {
   mvmt_.push_back(new MouvementDiagonale(1));
   mvmt_.push_back(new MouvementVertical(1));
   mvmt_.push_back(new MouvementHorizontal(1));
   roque_ = std::unique_ptr<Mouvement>(new MouvementRock(5));
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
   return moveTo(dep,but,e);
}

bool Roi::roque(Coord dep, Coord but, Echiquier *e) {
   return roque_->isMoveOk(dep,but,e,posInitiale_);
}
