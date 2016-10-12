
#include "MouvementHorizontal.hpp"


MouvementHorizontal::MouvementHorizontal(int d, bool saut) : Mouvement(d,saut) {}

MouvementHorizontal::~MouvementHorizontal() {}


bool MouvementHorizontal::isMoveOk(Coord &dep, Coord &but, Echiquier *e){
   bool isOk = true;
   int y;
   std::cout << "isMoveok\n";
   if(dep.y < but.y) {
      y = dep.y+1;
      while( y <= but.y ) {
         if(e->estOccupee(but.x,y)) isOk = false;
         std::cout << e->estOccupee(but.x,y) << "\n";
         ++y;
      }
   }
   else {
      y = dep.y-1;
      while( y >= but.y ) {
         if(e->estOccupee(but.x, y)) isOk = false;

         std::cout << e->estOccupee(but.x,y) << "\n";
         --y;
      }
   }

   return isOk;
}
