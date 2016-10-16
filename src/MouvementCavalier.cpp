
#include "MouvementCavalier.hpp"


MouvementCavalier::MouvementCavalier(int d) : Mouvement(d) {}

MouvementCavalier::~MouvementCavalier() {}


bool MouvementCavalier::isMoveOk(Coord &dep, Coord &but, Echiquier *e){
   bool isOk = false;

   if( !(e->estOccupee(but.x,but.y)) ) {
      if(dep.x+2 == but.x && dep.y+1 == but.y) isOk = true;
      else if(dep.x+2 == but.x && dep.y-1 == but.y) isOk = true;
      else if(dep.x-2 == but.x && dep.y+1 == but.y) isOk = true;
      else if(dep.x-2 == but.x && dep.y-1 == but.y) isOk = true;
      else if(dep.y+2 == but.y && dep.x+1 == but.x) isOk = true;
      else if(dep.y+2 == but.y && dep.x-1 == but.x) isOk = true;
      else if(dep.y-2 == but.y && dep.x+1 == but.x) isOk = true;
      else if(dep.y-2 == but.y && dep.x-1 == but.x) isOk = true;
   }

   return isOk;
}

bool MouvementCavalier::isAttackOk(Coord &dep, Coord &but, Echiquier *e) {
   return isMoveOk(dep,but,e);
}
