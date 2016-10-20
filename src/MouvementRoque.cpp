
#include "MouvementRoque.hpp"


MouvementRoque::MouvementRoque(int d) : Mouvement(d) {}

MouvementRoque::~MouvementRoque() {}


bool MouvementRoque::isMoveOk(Coord &dep, Coord &but, Echiquier *e, bool posInit){
   auto i = -1;
   Coord coordRoi = e->getType(dep) == 'R' ? dep : but;
   Coord coordTour = e->getType(dep) == 'T' ? dep : but;

   if( (e->getType(but) == 'R' || e->getType(but) == 'T') && posInit && e->pieceEnPosInit(but.x,but.y) ) {
      if(!e->estEchec(coordRoi)) {

         if(coordRoi.y < coordTour.y) {
            std::cout << "if\n ";
            i = coordRoi.y+1;

            while (i <= coordRoi.y+2 && !e->estEchec(Coord(coordRoi.x,i)) && !e->estOccupee(Coord(coordRoi.x,i))) { ++i; }
            if( i == coordRoi.y+2 ) {
               ++i;
               while((i < coordTour.y && !e->estOccupee(Coord(coordRoi.x,i)))) { ++i; }
            }
         }
         else {
            i = coordRoi.y-1;
            while (i >= coordRoi.y-2 && !e->estEchec(Coord(coordRoi.x,i)) && !e->estOccupee(Coord(coordRoi.x,i))) { -i; }
            if( i == coordRoi.y-2 ) {
               --i;
               while((i > coordTour.y && !e->estOccupee(Coord(coordRoi.x,i)))) { --i; }
            }
         }
      }
   }
   return (i == coordTour.y);
}


bool MouvementRoque::isAttackOk(Coord &dep, Coord &but, Echiquier *e, bool posInit) {
   return false;
}
