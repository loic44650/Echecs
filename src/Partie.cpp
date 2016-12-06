#include "Partie.hpp"

      /**
       * @brief
       *
       * @complexité
      **/
Partie::Partie() {
      e_ = std::shared_ptr<Echiquier>(new Echiquier());
}

      /**
       * @brief
       *
       * @complexité
      **/
void Partie::setPartie(const std::string& filename)
{
   e_->setEchiquier(filename);
   estEchec_ = false;
   roiDe_[0] = e_->findPiece('R',joueur_[0].getCouleur());
   roiDe_[1] = e_->findPiece('R',joueur_[1].getCouleur());
}

      /**
       * @brief
       *
       * @complexité
      **/
void Partie::lancer() {
   //on commence par le joueur qui a pris les blancs
   int numJoueur = (joueur_[0].getCouleur() == 'B') ? 0 : 1;

   while(!estEchec_) {
      e_->afficher();

      std::cout << "Tour de " << joueur_[numJoueur].sePresenter() << "\n";

      int choix = menu();

      if(choix == 1) afficherMouvementPiece(numJoueur);
      numJoueur = (numJoueur+1) % NB_JOUEURS;
   }
}

      /**
       * @brief
       *
       * @complexité
      **/
bool Partie::jouer(const Coord& dep, const Coord& arrivee, const char joueur) 
{
   bool moveDone = false;

   if (joueur == joueur_[joueurActuel_].getCouleur()) 
   {
      std::cerr << "tour du joueur " << joueurActuel_ << std::endl;
      
      if (e_->move(dep, arrivee)) 
      {
         joueurActuel_ = (joueurActuel_ + 1) % NB_JOUEURS;
         moveDone = true;
         std::cerr << "deplacement ok, joueur suivant" << std::endl;
      }
   }

   return moveDone;
}

      /**
       * @brief
       *
       * @complexité
      **/
Coord Partie::selectionnerPiece(std::string msg) {
   std::string strDep;
   std::cout << msg;
   std::cin >> strDep;
   return Coord(strDep);
}

      /**
       * @brief
       *
       * @complexité
      **/
int Partie::menu() {
   int choix = 0;

   std::cout << "1. Donner les mouvements possibles d'une pièce \n";
   std::cout << "2. Déplacer une pièce\n";
   std::cin >> choix;

   if(choix != 1 && choix != 2) menu();

   return choix;
}

      /**
       * @brief
       *
       * @complexité
      **/
void Partie::afficherMouvementPiece(int numJoueur) {
   Coord dep;

   do {
      dep = selectionnerPiece("Selectionne la pièce dont vous souhaitez voir les mouvements possibles : ");
   } while(!e_->estOccupee(dep) || (e_->getCouleur(dep) != joueur_[numJoueur].getCouleur()) );

   std::vector<Coord> tousLesMouvements = e_->mouvementPossible(dep);
   if(!tousLesMouvements.empty())
      for(auto c : tousLesMouvements) std::cout << c.toString() << " ";
   else
      std::cout << "Aucun mouvment possible pour cette pièce.";
   std::cout << std::endl;
}

      /**
       * @brief
       *
       * @complexité
      **/
void Partie::setJoueur(Joueur j, int i) {
   joueur_[i].setJoueur(j);
}

void Partie::init() 
{
   if (joueur_[0].getCouleur() == 'B')
      joueurActuel_ = 0;
   else
      joueurActuel_ = 1;
}

std::shared_ptr<Echiquier> Partie::getEchiquier() { return e_; }
