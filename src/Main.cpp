#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>
#include "Fenetre.hpp"
#include "Partie.hpp"
#include "Joueur.hpp"

using namespace std;


Joueur creerJoueur(char col);


int main(int argc, char* argv[])
{

	QApplication app(argc, argv);

   	shared_ptr<Partie> p = shared_ptr<Partie>(new Partie());
   	shared_ptr<Controleur> c = shared_ptr<Controleur>(new Controleur(p));
   	Fenetre fenetre(c);
   	//fenetre.show();

   	return app.exec();
		//return 0;
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
