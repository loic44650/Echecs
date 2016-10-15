
#include "MouvementDiagonale.hpp"


MouvementDiagonale::MouvementDiagonale(int d) : Mouvement(d) {}

MouvementDiagonale::~MouvementDiagonale() {}


bool MouvementDiagonale::isMoveOk(Coord &dep, Coord &but, Echiquier *e){
   bool isOk = true;
   int x;

   if(dep.y != but.y) return false;

   if(dep.x < but.x) {
      x = dep.x+1;
      while( x <= but.x ) {
         if(e->estOccupee(x,but.y)) isOk = false;
         ++x;
      }
   }
   else {
      x = dep.x-1;
      while( x >= but.x ) {
         if(e->estOccupee(x, but.y)) isOk = false;
         --x;
      }
   }

   return isOk;
}
