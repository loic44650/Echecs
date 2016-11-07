#include <iostream>
#include <cstdlib>
#include <string>

#include "Partie.hpp"
#include "Joueur.hpp"

using namespace std;

Joueur creerJoueur(char col);

int main(int argc, char* argv[])
{
   Joueur j1 = creerJoueur('B');
   Joueur j2 = creerJoueur('N');

   Partie partie("echiquierDeBase.txt",j1,j2);
   partie.lancer();

   return 0;
}


Joueur creerJoueur(char col) {
   string nom, prenom;

   cout << "Entrez votre nom : " << endl;
   cin >> nom;
   cout << "Entrez votre prenom : " << endl;
   cin >> prenom;

   return Joueur(nom, prenom, col);
}
