
#include "Roi.hpp"


Roi::Roi(int id, bool etat, char c) : Piece(id,etat,c), echec_(false), echecEtMat_(false) {
   mvmt_.push_back(new MouvementDiagonale(1));
   mvmt_.push_back(new MouvementVertical(1));
   mvmt_.push_back(new MouvementHorizontal(1));
   mvmt_.push_back(new MouvementRock(4));
}

Roi::~Roi() {}

char Roi::afficher() {
   return 'R';
}

bool Roi::moveTo(Coord dep, Coord but, Echiquier *e) {
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk) {
      mvmtOk = mvmt_[i]->isMoveOk(dep, but, e, posInitiale_);
      ++i;
   }
   if(mvmtOk) posInitiale_ = false;
   return mvmtOk;
}

bool Roi::attaquer(Coord dep, Coord but, Echiquier *e) {
   return moveTo(dep,but,e);
}
