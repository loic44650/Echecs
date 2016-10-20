
#include "MouvementVertical.hpp"


MouvementVertical::MouvementVertical(int d) : Mouvement(d) {}

MouvementVertical::~MouvementVertical() {}

bool MouvementVertical::peutAllerEn(Coord &dep, Coord &but, Echiquier *e) {
   bool isOk = true;
   int x;

   if(dep.y != but.y) return false;

   if(dep.x < but.x) {
      x = dep.x+1;

      while( x < but.x && (x-dep.x) <= distance_) {
         if(e->estOccupee(Coord(x,but.y))) isOk = false;
         ++x;
      }
   }
   else {
      x = dep.x-1;

      while( x > but.x && (dep.x-x) <= distance_) {
         if(e->estOccupee(Coord(x, but.y))) isOk = false;
         --x;
      }
   }

   return isOk;
}

bool MouvementVertical::isMoveOk(Coord &dep, Coord &but, Echiquier *e, bool posInit){

   if(peutAllerEn(dep,but,e)) {
      e->movePiece(dep,but);
      return true;
   }

   return false;
}

bool MouvementVertical::isAttackOk(Coord &dep, Coord &but, Echiquier *e, bool posInit) {

   if(peutAllerEn(dep,but,e)) {
      e->mangerPiece(dep,but);
      return true;
   }

   return false;
}
