
#include "MouvementDiagonale.hpp"
<<<<<<< HEAD

=======
#include <cstdlib>
>>>>>>> mouvement_pieces

MouvementDiagonale::MouvementDiagonale(int d) : Mouvement(d) {}

MouvementDiagonale::~MouvementDiagonale() {}


bool MouvementDiagonale::isMoveOk(Coord &dep, Coord &but, Echiquier *e){
   bool isOk = true;
<<<<<<< HEAD
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
=======
   int x, y;

   if(abs(dep.x-but.x) != abs(dep.y-but.y)) return false;

   if(but.x < dep.x && but.y < dep.y) {
      x = dep.x-1;
      y = dep.y-1;
      while( x >= but.x && (dep.x-x) <= distance_) {
         if(e->estOccupee(x,y)) isOk = false;
         --x;
         --y;
      }
   }
   else if(but.x < dep.x && but.y > dep.y) {
      x = dep.x-1;
      y = dep.y+1;
      while( x <= but.x && (dep.x-x) <= distance_) {
         if(e->estOccupee(x,y)) isOk = false;
         --x;
         ++y;
      }
   }
   else if(but.x > dep.x && but.y < dep.y) {
      x = dep.x+1;
      y = dep.y-1;
      while( x >= but.x && (x-dep.x) <= distance_) {
         if(e->estOccupee(x,y)) isOk = false;
         ++x;
         --y;
      }
   }
   else if(but.x > dep.x && but.y > dep.y) {
      x = dep.x+1;
      y = dep.y+1;
      while( x >= but.x && (x-dep.x) <= distance_) {
         if(e->estOccupee(x,y)) isOk = false;
         ++x;
         ++y;
>>>>>>> mouvement_pieces
      }
   }

   return isOk;
}
