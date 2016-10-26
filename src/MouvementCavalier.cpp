
#include "MouvementCavalier.hpp"


MouvementCavalier::MouvementCavalier(int d) : Mouvement(d) {}

MouvementCavalier::~MouvementCavalier() {}

bool MouvementCavalier::peutAllerEn(Coord &dep, Coord &but, Echiquier *e) {
   bool isOk = false;

   if(dep.x+2 == but.x && dep.y+1 == but.y) isOk = true;
   else if(dep.x+2 == but.x && dep.y-1 == but.y) isOk = true;
   else if(dep.x-2 == but.x && dep.y+1 == but.y) isOk = true;
   else if(dep.x-2 == but.x && dep.y-1 == but.y) isOk = true;
   else if(dep.y+2 == but.y && dep.x+1 == but.x) isOk = true;
   else if(dep.y+2 == but.y && dep.x-1 == but.x) isOk = true;
   else if(dep.y-2 == but.y && dep.x+1 == but.x) isOk = true;
   else if(dep.y-2 == but.y && dep.x-1 == but.x) isOk = true;

   return isOk;
}

bool MouvementCavalier::isMoveOk(Coord &dep, Coord &but, Echiquier *e, bool posInit){
   if(peutAllerEn(dep,but,e)) {
      e->movePiece(dep,but);
      return true;
   }

   return false;
}

bool MouvementCavalier::isAttackOk(Coord &dep, Coord &but, Echiquier *e, bool posInit) {
   if(peutAllerEn(dep,but,e)) {
      e->mangerPiece(dep,but);
   }
}
