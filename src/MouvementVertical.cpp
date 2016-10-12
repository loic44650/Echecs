
#include "MouvementVertical.hpp"


MouvementVertical::MouvementVertical(int d, bool saut) : Mouvement(d,saut) {}

MouvementVertical::~MouvementVertical() {}


bool MouvementVertical::isMoveOk(Coord &dep, Coord &but, Echiquier *e){
   bool isOk = true;
   int x;
   std::cout << "isMoveok\n";
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
