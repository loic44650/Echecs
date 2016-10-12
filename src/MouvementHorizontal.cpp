
#include "MouvementHorizontal.hpp"


MouvementHorizontal::MouvementHorizontal(int d, bool saut) : Mouvement(d,saut) {}

MouvementHorizontal::~MouvementHorizontal() {}


bool MouvementHorizontal::isMoveOk(Coord &dep, Coord &but, Echiquier *e){
   bool isOk = true;
   int y;

   if(dep.y < but.y) {
      y = dep.y+1;
      while( y <= but.y ) {
         if(e->estOccupee(but.x,y)) isOk = false;
         ++y;
      }
   }
   else {
      y = dep.y-1;
      while( y >= but.y ) {
         if(e->estOccupee(but.x, y)) isOk = false;
         --y;
      }
   }

   return isOk;
}
