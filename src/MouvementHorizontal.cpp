
#include "MouvementHorizontal.hpp"


MouvementHorizontal::MouvementHorizontal(int d) : Mouvement(d) {}

MouvementHorizontal::~MouvementHorizontal() {}

bool MouvementHorizontal::peutAllerEn(Coord &dep, Coord &but, Echiquier *e) {
   bool isOk = true;
   int y;

   if(dep.x != but.x) return false;

   if(dep.y < but.y) {
      y = dep.y+1;

      while( y < but.y && (y-dep.y) <= distance_) {
         if(e->estOccupee(Coord(but.x,y))) isOk = false;
         ++y;
      }
   }
   else {
      y = dep.y-1;

      while( y > but.y && (dep.y-y) <= distance_) {
         if(e->estOccupee(Coord(but.x, y))) isOk = false;
         --y;
      }
   }

   return isOk;
}

bool MouvementHorizontal::isMoveOk(Coord &dep, Coord &but, Echiquier *e, bool posInit){

   if(peutAllerEn(dep,but,e)) {
      e->movePiece(dep,but);
      return true;
   }

   return false;
}

bool MouvementHorizontal::isAttackOk(Coord &dep, Coord &but, Echiquier *e, bool posInit) {
   if(peutAllerEn(dep,but,e)) {
      e->mangerPiece(dep,but);
      return true;
   }

   return false;
}
