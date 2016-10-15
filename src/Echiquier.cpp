#include "Echiquier.hpp"
#include "Piece.hpp"
#include "Pion.hpp"
#include "Tour.hpp"
#include "Fou.hpp"
#include "Roi.hpp"
#include "Reine.hpp"
#include "Cavalier.hpp"

Echiquier::Echiquier() {
   for(auto i = 0; i < 8; ++i) {
      echiquier_[1][i] = std::shared_ptr<Piece>(new Pion(i, true, 'N'));
      echiquier_[6][i] = std::shared_ptr<Piece>(new Pion(i, true, 'B'));
   }
   echiquier_[0][0] = std::shared_ptr<Piece>(new Tour(9, true, 'N'));
   echiquier_[0][1] = std::shared_ptr<Piece>(new Cavalier(9, true, 'N'));
   echiquier_[0][2] = std::shared_ptr<Piece>(new Fou(9, true, 'N'));
   echiquier_[0][3] = std::shared_ptr<Piece>(new Reine(9, true, 'N'));
   echiquier_[0][4] = std::shared_ptr<Piece>(new Roi(9, true, 'N'));
   echiquier_[0][5] = std::shared_ptr<Piece>(new Fou(9, true, 'N'));
   echiquier_[0][6] = std::shared_ptr<Piece>(new Cavalier(9, true, 'N'));
   echiquier_[0][7] = std::shared_ptr<Piece>(new Tour(9, true, 'N'));

   echiquier_[7][0] = std::shared_ptr<Piece>(new Tour(9, true, 'B'));
   echiquier_[7][1] = std::shared_ptr<Piece>(new Cavalier(9, true, 'B'));
   echiquier_[7][2] = std::shared_ptr<Piece>(new Fou(9, true, 'B'));
   echiquier_[7][3] = std::shared_ptr<Piece>(new Roi(9, true, 'B'));
   echiquier_[7][4] = std::shared_ptr<Piece>(new Reine(9, true, 'B'));
   echiquier_[7][5] = std::shared_ptr<Piece>(new Cavalier(9, true, 'B'));
   echiquier_[7][6] = std::shared_ptr<Piece>(new Fou(9, true, 'B'));
   echiquier_[7][7] = std::shared_ptr<Piece>(new Tour(10, true, 'B'));
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
   Color::Modifier lblue(Color::BG_LIGHTBLUE);
   Color::Modifier black(Color::FG_BLACK);
   Color::Modifier white(Color::FG_WHITE);
   Color::Modifier fg_def(Color::FG_DEFAULT);
   Color::Modifier bg_def(Color::BG_DEFAULT);

   std::cout << "  ";
   for(auto i = 0; i < 8; ++i) std::cout << " " << char('A'+i) << " ";
   std::cout << "\n";

   for(auto i = 0; i < 8; ++i) {
      std::cout << 8-i << " ";
      for(auto j = 0; j < 8; ++j) {
         if((i+j)%2) std::cout << lgrey;
         else std::cout << lblue;
         if ( echiquier_[i][j] ) {
            if(echiquier_[i][j]->getCouleur() == 'B')
               std::cout << white << " " << echiquier_[i][j]->afficher() << " ";
            else
               std::cout << black << " " << echiquier_[i][j]->afficher() << " ";
         }
         else std::cout << "   ";
      }
      std::cout << fg_def << bg_def << "\n";
   }
   std::cout << "  ";
   for(auto i = 0; i < 8; ++i) std::cout << " " << char('A'+i) << " ";
   std::cout << "\n";
}


void Echiquier::count_ptr() {
   for(auto i = 0; i < 8; ++i) {
      for(auto j = 0; j < 8; ++j)
         std::cout << "(" << i << "," << j << ")" <<  echiquier_[i][j].use_count() << std::endl;
   }
}


bool Echiquier::move(Coord dep, Coord but) {
   bool mvmtEffectue = false;

   if(echiquier_[dep.x][dep.y]->moveTo(dep, but, this)) {
      echiquier_[but.x][but.y] = echiquier_[dep.x][dep.y];
      echiquier_[dep.x][dep.y] = nullptr;
      mvmtEffectue = true;
   }

   return mvmtEffectue;
}
