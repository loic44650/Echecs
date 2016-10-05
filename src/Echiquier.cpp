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

void Echiquier::afficher() {
   for(auto i = 0; i < 8; ++i) {
      for(auto j = 0; j < 8; ++j) {
         if ( echiquier_[i][j] ) (echiquier_[i][j])->afficher();
         else std::cout << "_|";
      }
      std::cout << std::endl;
   }
}


void Echiquier::count_ptr() {
   for(auto i = 0; i < 8; ++i) {
      for(auto j = 0; j < 8; ++j)
         std::cout << "(" << i << "," << j << ")" <<  echiquier_[i][j].use_count() << std::endl;
   }
}
