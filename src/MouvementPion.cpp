#include "MouvementPion.hpp"


MouvementPion::MouvementPion(int d, char dir) : Mouvement(d), direction_(dir) {}

MouvementPion::~MouvementPion() {}


bool MouvementPion::peutAllerEn(Coord &dep, Coord &but, Echiquier *e, bool posInit) {
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

bool MouvementPion::isMoveOk(Coord &dep, Coord &but, Echiquier *e, bool posInit){

   if(peutAllerEn(dep,but,e,posInit)) {
      e->movePiece(dep,but);
      return true;
   }

   return false;
}

bool MouvementPion::isAttackOk(Coord &dep, Coord &but, Echiquier *e, bool posInit) {
   bool peutAttaquer = false;
   bool colonneOk = (but.y - dep.y == 1 || dep.y-but.y) ? true : false;

   if(direction_ == 'S' && but.x == (dep.x+1) && colonneOk) peutAttaquer = true;
   else if(direction_ == 'N' && but.x == (dep.x-1) && colonneOk) peutAttaquer = true;

   if(peutAttaquer) 
      e->mangerPiece(dep,but);

   return peutAttaquer;
}
