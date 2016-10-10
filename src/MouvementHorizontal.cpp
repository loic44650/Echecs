
#include "MouvementHorizontal.hpp"


MouvementHorizontal::MouvementHorizontal(int d, bool saut) : Mouvement(d,saut) {}

MouvementHorizontal::~MouvementHorizontal() {}


std::vector<Coord> MouvementHorizontal::deplacement(Coord &dep, Echiquier &e) {
   std::vector<Coord> mvmt_possible;
   int g = 0, d = 0, i = 0;
   int x = dep.x, y = dep.y;
   Coord tmp;

   while( i < 8 && (g < i || d < i) ) {
      if( !e.estOccupee(x+i,y) ) {
         d = i;
         tmp.x = x+i; tmp.y = y;
         mvmt_possible.push_back(tmp);
      }
      if( !e.estOccupee(x-i,y) ) {
         g = i;
         tmp.x = x-i; tmp.y = y;
         mvmt_possible.push_back(tmp);
      }
   }

   return mvmt_possible;
}
