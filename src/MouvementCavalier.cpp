
#include "MouvementCavalier.hpp"


MouvementCavalier::MouvementCavalier(int d) : Mouvement(d) {}

MouvementCavalier::~MouvementCavalier() {}


bool MouvementCavalier::isMoveOk(Coord &dep, Coord &but, Echiquier *e){
   bool isOk = false;

   if( !(e->estOccupee(but.x,but.y)) ) {
      if(dep.x+3 == but.x && dep.y+1 == but.y) isOk = true;
      else if(dep.x+3 == but.x && dep.y-1 == but.y) isOk = true;
      else if(dep.x-3 == but.x && dep.y+1 == but.y) isOk = true;
      else if(dep.x-3 == but.x && dep.y-1 == but.y) isOk = true;
      else if(dep.y+3 == but.y && dep.x+1 == but.x) isOk = true;
      else if(dep.y+3 == but.y && dep.x-1 == but.x) isOk = true;
      else if(dep.y-3 == but.y && dep.x+1 == but.x) isOk = true;
      else if(dep.y-3 == but.y && dep.x-1 == but.x) isOk = true;
   }

   return isOk;
}
