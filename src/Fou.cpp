
#include "Fou.hpp"


Fou::Fou(int id, bool etat, char c) : Piece(id,etat,c) {
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
   return moveTo(dep,but,e);
}
