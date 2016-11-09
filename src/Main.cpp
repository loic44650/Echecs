#include <iostream>
#include <cstdlib>
#include <string>

#include "Fenetre.hpp"
#include "Partie.hpp"
#include "Joueur.hpp"

using namespace std;


Joueur creerJoueur(char col);


int main(int argc, char* argv[])
{

	QApplication app(argc, argv);
   
   	Partie p;
   	Controleur c(&p);
   	Fenetre fenetre(&c);
   	fenetre.show();
   	
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
