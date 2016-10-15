
#include "MouvementHorizontal.hpp"


MouvementHorizontal::MouvementHorizontal(int d) : Mouvement(d) {}

MouvementHorizontal::~MouvementHorizontal() {}


bool MouvementHorizontal::isMoveOk(Coord &dep, Coord &but, Echiquier *e){
   bool isOk = true;
   int y;

   if(dep.x != but.x) return false;

   if(dep.y < but.y) {
      y = dep.y+1;
<<<<<<< HEAD
      while( y <= but.y ) {
=======
      while( y <= but.y && (y-dep.y) <= distance_) {
>>>>>>> mouvement_pieces
         if(e->estOccupee(but.x,y)) isOk = false;
         ++y;
      }
   }
   else {
      y = dep.y-1;
<<<<<<< HEAD
      while( y >= but.y ) {
=======
      while( y >= but.y && (dep.y-y) <= distance_) {
>>>>>>> mouvement_pieces
         if(e->estOccupee(but.x, y)) isOk = false;
         --y;
      }
   }

   return isOk;
}
