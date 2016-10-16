#include "MouvementPion.hpp"


MouvementPion::MouvementPion(int d, char dir) : Mouvement(d), direction_(dir) {}

MouvementPion::~MouvementPion() {}


bool MouvementPion::isMoveOk(Coord &dep, Coord &but, Echiquier *e, bool posInit){
   bool isOk = false;

   if(dep.y != but.y || dep.x == but.x) return false;
   else if(posInit) {
      if(direction_ == 'S' && but.x <= dep.x+2 ) isOk = true;
      else if(direction_ == 'N' && dep.x <= but.x+2) isOk = true;
      else isOk = false;
   }
   else {
      if(direction_ == 'S' && but.x == (dep.x+1) ) isOk = true;
      else if(direction_ == 'N' && but.x == (dep.x-1) ) isOk = true;
      else isOk = false;
   }
   return isOk;
}

bool MouvementPion::isAttackOk(Coord &dep, Coord &but, Echiquier *e, bool posInit) {
   if(direction_ == 'S' && but.x == (dep.x+1) && abs(but.y-dep.y) == 1) return true;
   else if(direction_ == 'N' && but.x == (dep.x-1) && abs(but.y-dep.y) == 1) return true;
   else return false;
}
