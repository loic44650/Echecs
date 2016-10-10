
#include "Tour.hpp"


Tour::Tour(int id, bool etat, char c) : Piece(id,etat,c) {
   MouvementHorizontal mvmtH(8,false);
   mvmt_.push_back(mvmtH);
}

Tour::~Tour() {}

char Tour::afficher() {
   return 'T';
}

void Tour::deplacement(Coord &c, Echiquier &e) {
   std::vector<Coord> mvmt_possible;
   for(auto m : mvmt_) {
      mvmt_possible = m.deplacement(c, e);
   }
}
