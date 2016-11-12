#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>
#include "Fenetre.hpp"
#include "Partie.hpp"
#include "Joueur.hpp"

using namespace std;


int main(int argc, char* argv[])
{

	QApplication app(argc, argv);

   	shared_ptr<Partie> p = shared_ptr<Partie>(new Partie());
   	shared_ptr<Controleur> c = shared_ptr<Controleur>(new Controleur(p));
   	Fenetre fenetre(c);
   	fenetre.show();

   	return app.exec();
}
