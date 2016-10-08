#include "Echiquier.hpp"


Echiquier::Echiquier() {
   for(auto i = 0; i < 8; ++i)
      echiquier_[1][i] = std::shared_ptr<Piece>(new Pion(i, true, 'N'));
}

Echiquier::~Echiquier() {
   for(auto i = 0; i < 8; ++i) {
      for(auto j = 0; j < 8; ++j)
         echiquier_[i][j].reset();
   }
}


bool Echiquier::estOccupee(int x, int y) {
   if( echiquier_[x][y]) return true;
   else return false;
}

void Echiquier::afficher() {
   Color::Modifier lgrey(Color::BG_LIGHTGREY);
   Color::Modifier bgrey(Color::BG_DARKGRAY);
   Color::Modifier black(Color::FG_BLACK);
   Color::Modifier white(Color::FG_WHITE);
   for(auto i = 0; i < 8; ++i) {
      for(auto j = 0; j < 8; ++j) {
         if((i+j)%2) std::cout << lgrey;
         else std::cout << bgrey;
         if ( echiquier_[i][j] ) std::cout << " " << (echiquier_[i][j])->afficher() << " ";
         else std::cout << "   ";
      }
      std::cout << std::endl;
   }
   Color::Modifier fg_def(Color::FG_DEFAULT);
   Color::Modifier bg_def(Color::BG_DEFAULT);
   std::cout << fg_def << bg_def << std::endl;
}


void Echiquier::count_ptr() {
   for(auto i = 0; i < 8; ++i) {
      for(auto j = 0; j < 8; ++j)
         std::cout << "(" << i << "," << j << ")" <<  echiquier_[i][j].use_count() << std::endl;
   }
}
