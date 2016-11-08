#include <iostream>
#include <cstdlib>
#include <string>
#include <QApplication>

#include "Fenetre.hpp"
#include "Partie.hpp"
#include "Joueur.hpp"

using namespace std;


Joueur creerJoueur(char col);


int main(int argc, char* argv[])
{

	QApplication app(argc, argv);

	Fenetre fenetre;
    fenetre.show();
    

    /*
    Joueur j1 = creerJoueur('B');
    Joueur j2 = creerJoueur('N');

    Partie partie("echiquierDeBase.txt",j1,j2);
    partie.lancer();
	*/
   	
   	return app.exec();
}

Joueur creerJoueur(char col)
{
   string nom, prenom;

   cout << "Entrez votre nom : " << endl;
   cin >> nom;
   cout << "Entrez votre prenom : " << endl;
   cin >> prenom;

   return Joueur(nom, prenom, col);
}
