#include "Echiquier.hpp"
#include "FactoryPiece.hpp"
#include "Piece.hpp"

Echiquier::Echiquier() {}

Echiquier::Echiquier(const std::string &nomFichier) : dernierePieceMangee_(nullptr)
{
   FactoryPiece fp;
   std::ifstream fichier(nomFichier, std::ifstream::in);

   if (fichier.is_open())
   {
      int x, y;
      std::string nomPiece;
      char dir;

      fichier >> x >> y >> nomPiece >> dir;
      echiquier_[x][y] = fp.creerPiece(nomPiece, dir);

      while (fichier.good())
      {
         fichier >> x >> y >> nomPiece >> dir;
         echiquier_[x][y] = fp.creerPiece(nomPiece, dir);
      }
      fichier.close();
   }
   else std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

Echiquier::~Echiquier() {}

void Echiquier::setEchiquier(const std::string &nomFichier)
{
   FactoryPiece fp;
   std::ifstream fichier(nomFichier, std::ifstream::in);

   if (fichier.is_open())
   {
      int x, y;
      std::string nomPiece;
      char dir;

      fichier >> x >> y >> nomPiece >> dir;
      std::cerr << x << y << " " << nomPiece << " ,dir :" << dir << std::endl;
      echiquier_[x][y] = fp.creerPiece(nomPiece, dir);
      std::cerr << echiquier_[x][y]->getCouleur() << std::endl;

      while (fichier.good())
      {
         fichier >> x >> y >> nomPiece >> dir;
         echiquier_[x][y] = fp.creerPiece(nomPiece, dir);
      }

      fichier.close();
   }
   else std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

bool Echiquier::pieceEnPosInit(int x, int y) 
{
   return echiquier_[x][y]->pieceEnPosInit();
}

bool Echiquier::estOccupee(Coord coord) 
{
   if( echiquier_[coord.x][coord.y]) return true;
   else return false;
}

// Renvoie -1 si case occupée par pièce de meme couleur
// Renvoie 0 si case Vide
// Renvoie 1 si case occupée par pièce ennemie
int Echiquier::getTypeMouvement(Coord dep,Coord but) 
{
   if(echiquier_[but.x][but.y]) 
   {
      std::cerr << "getype mouvement if occupé " << std::endl;
      if(echiquier_[but.x][but.y]->getCouleur() == echiquier_[dep.x][dep.y]->getCouleur()) 
         {
            std::cerr << "getype mouvement if occupé meme couleur " << std::endl;
            return -1;
         }
      else  
      {
         std::cerr << "getype mouvement if occupé pas meme couleur " << std::endl;
         return 1;
      }
   }
   else  
   {
      std::cerr << "getype mouvement if non occupé " << std::endl;
      return 0;
   }
}

char Echiquier::getType(Coord c) 
{
   return echiquier_[c.x][c.y]->afficher();
}

char Echiquier::getCouleur(Coord c)
{
   return echiquier_[c.x][c.y]->getCouleur();
}

void Echiquier::afficher() 
{
   Color::Modifier lgrey(Color::BG_LIGHTGREY);
   Color::Modifier bgrey(Color::BG_DARKGRAY);
   Color::Modifier lblue(Color::BG_LIGHTBLUE);
   Color::Modifier black(Color::FG_BLACK);
   Color::Modifier white(Color::FG_WHITE);
   Color::Modifier fg_def(Color::FG_DEFAULT);
   Color::Modifier bg_def(Color::BG_DEFAULT);

   std:: cout << "\n  ";
   
   for(auto i = 0; i < 8; ++i) std::cout << " " << char('A'+i) << " ";
   
   std::cout << "\n";

   for(auto i = 0; i < 8; ++i) 
   {
      std::cout << 8-i << " ";
      
      for(auto j = 0; j < 8; ++j) 
      {
         if((i+j)%2) std::cout << lgrey;
         else std::cout << lblue;

         if ( echiquier_[i][j] ) 
         {
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

void Echiquier::movePiece(Coord dep, Coord but) 
{
   swap(echiquier_[dep.x][dep.y],echiquier_[but.x][but.y]);
}

void Echiquier::mangerPiece(Coord dep, Coord but) 
{
   echiquier_[but.x][but.y] = nullptr;
   swap(echiquier_[dep.x][dep.y],echiquier_[but.x][but.y]);
}

bool Echiquier::move(Coord dep, Coord but) 
{
   dernierePieceMangee_ = nullptr;

   bool mvmtEffectue = false;
   int typeMvmt = getTypeMouvement(dep,but);
   std::cout << "mouve choisis : " << typeMvmt << std::endl;
   
   // Case but vide
   if(typeMvmt == 0) {
      if(echiquier_[dep.x][dep.y]->moveTo(dep, but, this)) 
      {
         mvmtEffectue = true;
      }
   }
   // Case but occupée par pièce ennemie
   else if(typeMvmt == 1) 
   {
      Piece *p =  echiquier_[but.x][but.y].get();
      dernierePieceMangee_ = std::unique_ptr<Piece> (p);
      echiquier_[but.x][but.y].reset(p);
      
      if(echiquier_[dep.x][dep.y]->attaquer(dep,but,this))
      {
         mvmtEffectue = true;
      }
   }
   // Case but occupée par pièce amie : ROCK seul mvmt possible
   else 
   {
      if(echiquier_[dep.x][dep.y]->roquer(dep,but,this)) 
      {
         mvmtEffectue = true;
      }
   }

   return mvmtEffectue;
}

bool Echiquier::estEchec(Coord roi) 
{
   bool echec = false;
      
   char coulRoi = echiquier_[roi.x][roi.y]->getCouleur();
   Coord dep;

   for(int i = 0; i < 8; ++i) 
   {
      for(int j = 0; j < 8; ++j) 
      {
         if(echiquier_[i][j] && echiquier_[i][j]->getCouleur() != coulRoi) 
         {
            dep.x = i; dep.y = j;
              
            if(echiquier_[i][j]->attaquer(dep,roi,this)) 
            {
               echec = true;
               std::cout << "Echec par " << i << "," << j << std::endl;
            }
         }
      }
   }

   return echec;
}

bool Echiquier::estMat(Coord roi) 
{
   bool mat = true;
   Coord positionInitiale = roi;

   /*vector<Coord> movePoss;

   // estMat si -> ne peut changer de case sans etre echec
   //           -> aucune pièce amie ne peut manger la pièce ennemie
   //           -> aucune pièce amie ne peut se mettre devant son roi

   for (int i = 0; i < 8; ++i) 
   {
      for (int j = 0; j < 8; ++j) 
      {
         if (echiquier_[i][j] && echiquier_[i][j]->getCouleur() == coulRoi) 
         {
            movePoss = mouvementPossible(Coord(i, j));

            for (auto m : movePoss)
            {



               if (!estEchec(roi))
                  mat = false;
            }
         }
      }
   }*/

   return mat;
}

std::vector<Coord> Echiquier::mouvementPossible(Coord dep)
{
   return echiquier_[dep.x][dep.y]->mouvementPossible(dep,this);
}

Coord Echiquier::findPiece(char piece, char coul) 
{
   Coord res(-1,-1);

   for(int i = 0; i < 8; ++i) 
   {
      for(int j = 0; j < 8; ++j) 
      {
         if(echiquier_[i][j] && echiquier_[i][j]->afficher() == piece) 
         {
            if(echiquier_[i][j]->getCouleur() == coul) res = Coord(i,j);
         }
      }
   }

   return res;
}

void Echiquier::annulerCoup(Coord dep, Coord but)
{
   swap(echiquier_[dep.x][dep.y], echiquier_[but.x][but.y]);
 
   if (dernierePieceMangee_)
   {
      swap(echiquier_[but.x][but.y], dernierePieceMangee_);
   }
}