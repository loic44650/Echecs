#include "Partie.hpp"


Partie::Partie() {}

void Partie::setPartie(const std::string& filename)
{
   e_.setEchiquier(filename);
   estEchec_ = false;
   roiDe_[0] = e_.findPiece('R',joueur_[0].getCouleur());
   roiDe_[1] = e_.findPiece('R',joueur_[1].getCouleur());
}

void Partie::lancer() {
   //on commence par le joueur qui a pris les blancs
   int numJoueur = (joueur_[0].getCouleur() == 'B') ? 0 : 1;

   while(!estEchec_) {
      e_.afficher();

      std::cout << "Tour de " << joueur_[numJoueur].sePresenter() << "\n";

      int choix = menu();

      if(choix == 1) afficherMouvementPiece(numJoueur);
      else  jouer(numJoueur);
      numJoueur = (numJoueur+1) % NB_JOUEURS;
   }
}

void Partie::jouer(int numJoueur) {
   Coord dep, but;

   do {
      dep = selectionnerPiece("Selectionne la pièce à déplacer : ");
   } while(!e_.estOccupee(dep) || (e_.getCouleur(dep) != joueur_[numJoueur].getCouleur()) );

   but = selectionnerPiece("Sélectionne la case d'arrivée : ");

   if(e_.move(dep,but)) {
      // Si c'est le roi qui a été déplacé, mettre a jour ses coordonnées
      if(e_.estOccupee(roiDe_[numJoueur])) roiDe_[numJoueur] = e_.findPiece('R',joueur_[numJoueur].getCouleur());
   }

   estEchec_ = e_.estEchec(roiDe_[numJoueur]);
}

Coord Partie::selectionnerPiece(std::string msg) {
   std::string strDep;
   std::cout << msg;
   std::cin >> strDep;
   return Coord(strDep);
}

int Partie::menu() {
   int choix = 0;

   std::cout << "1. Donner les mouvements possibles d'une pièce \n";
   std::cout << "2. Déplacer une pièce\n";
   std::cin >> choix;

   if(choix != 1 && choix != 2) menu();

   return choix;
}

void Partie::afficherMouvementPiece(int numJoueur) {
   Coord dep;

   do {
      dep = selectionnerPiece("Selectionne la pièce dont vous souhaitez voir les mouvements possibles : ");
   } while(!e_.estOccupee(dep) || (e_.getCouleur(dep) != joueur_[numJoueur].getCouleur()) );

   std::vector<Coord> tousLesMouvements = e_.mouvementPossible(dep);
   if(!tousLesMouvements.empty())
      for(auto c : tousLesMouvements) std::cout << c.toString() << " ";
   else
      std::cout << "Aucun mouvment possible pour cette pièce.";
   std::cout << std::endl;
}

void Partie::setJoueur(Joueur j, int i) {
   joueur_[i].setJoueur(j);
}

Echiquier& Partie::getEchiquier() { return e_; }
