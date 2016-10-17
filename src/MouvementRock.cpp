
#include "MouvementRock.hpp"


MouvementRock::MouvementRock(int d) : Mouvement(d) {}

MouvementRock::~MouvementRock() {}


bool MouvementRock::isMoveOk(Coord &dep, Coord &but, Echiquier *e, bool posInit){
   auto i = -1;
   Coord coordRoi = e->getType(dep) == 'R' ? dep : but;
   Coord coordTour = e->getType(dep) == 'T' ? dep : but;

   if( (e->getType(but) == 'R' || e->getType(but) == 'T') && posInit && e->pieceEnPosInit(but.x,but.y) ) {

      if(coordRoi.y < coordTour.y) {
         std::cout << "if\n ";
         i = coordRoi.y+1;
         auto j = i;
         while((i < coordTour.y && !e->estOccupee(coordRoi.x,i) || (j<=coordRoi.y+2 && e->estEchec(Coord(coordRoi.x,j))))) {
            std::cout << "i: " << i << "\n";
            ++i; ++j;
         }
      }
      else {
         i = coordRoi.y-1;
         auto j = i;
         while((i > coordTour.y && !e->estOccupee(coordRoi.x,i) || (j>=coordRoi.y-2 && e->estEchec(Coord(coordRoi.x,j))))) {
            --i; --j;
            std::cout << "i: " << i << "\n";
         }
      }
   }
   std::cout << "return i=" << i << "\n";
   return (i == coordTour.y);
}

bool MouvementRock::isAttackOk(Coord &dep, Coord &but, Echiquier *e, bool posInit) {
   return false;
}
