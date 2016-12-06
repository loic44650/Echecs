#include "Fenetre.hpp"

Fenetre::Fenetre(std::shared_ptr<Controleur> controleur) : QWidget(), controleur_(controleur)
{
   setFixedSize(800, 800);
   setWindowIcon(QIcon("picture/logo.png"));
   setWindowTitle("Echecs");

    boutonNewGame_ = new QPushButton("New Game vs IA", this);
    boutonNewGame_->setCursor(Qt::PointingHandCursor);
    QObject::connect(boutonNewGame_, SIGNAL(clicked()), this, SLOT(ouvrirDialogueNewGameVSIA()));

    boutonNewGameBis_ = new QPushButton("New game vs player", this);
    boutonNewGameBis_->setCursor(Qt::PointingHandCursor);
    boutonNewGameBis_->move(125, 0);
    QObject::connect(boutonNewGameBis_, SIGNAL(clicked()), this, SLOT(ouvrirDialogueNewGameVSPlayer()));

    boutonAbout_ = new QPushButton("A propos", this);
    boutonAbout_->setCursor(Qt::PointingHandCursor);
    boutonAbout_->move(277, 0);
    QObject::connect(boutonAbout_, SIGNAL(clicked()), this, SLOT(ouvrirMessageAbout()));

}

Fenetre::~Fenetre() {/*
   for(int i = 0; i < NB_CASES; ++i) {
      for(int j = 0; j < NB_CASES; ++j)
      delete cases[i][j];
   }
      delete plateau_;*/
}
void Fenetre::ouvrirDialogueNewGameVSIA()
{
	QWidget *sousFenetre = new QWidget;

	QLineEdit *nom = new QLineEdit;
	QLineEdit *prenom = new QLineEdit;
	QComboBox *liste = new QComboBox;
   liste->addItem("");
	liste->addItem("Blanc");
	liste->addItem("Noir");

	QFormLayout *formLayout = new QFormLayout;
	formLayout->addRow("Votre &nom", nom);
	formLayout->addRow("Votre &prenom", prenom);
	formLayout->addRow("votre &couleur", liste);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addLayout(formLayout);

	QPushButton *boutonStart = new QPushButton("Lancer");
	layout->addWidget(boutonStart);

	sousFenetre->setLayout(layout);

	sousFenetre->show();

   	QObject::connect(nom, SIGNAL(textChanged(QString)), this, SLOT(ecrireNom(QString)));
   	QObject::connect(prenom, SIGNAL(textChanged(QString)), this, SLOT(ecrirePrenom(QString)));
   	QObject::connect(liste, SIGNAL(currentTextChanged(QString)), this, SLOT(ecrireCol(QString)));
	QObject::connect(boutonStart, SIGNAL(clicked()), this, SLOT(startGameVSIA()));
	QObject::connect(boutonStart, SIGNAL(clicked()), sousFenetre, SLOT(hide()));
}


void Fenetre::ouvrirDialogueNewGameVSPlayer()
{
	QWidget *sousFenetre = new QWidget;

	QLineEdit *nom = new QLineEdit;
	QLineEdit *prenom = new QLineEdit;
	QComboBox *liste = new QComboBox;
	liste->addItem("Blanc");
	liste->addItem("Noir");

	QFormLayout *formLayout = new QFormLayout;
	formLayout->addRow("Votre &nom", nom);
	formLayout->addRow("Votre &prenom", prenom);
	formLayout->addRow("votre &couleur", liste);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addLayout(formLayout);

	QPushButton *boutonSuivant = new QPushButton("Suivant");
	layout->addWidget(boutonSuivant);

	sousFenetre->setLayout(layout);

	sousFenetre->show();

   	QObject::connect(nom, SIGNAL(textChanged(QString)), this, SLOT(ecrireNom(QString)));
   	QObject::connect(prenom, SIGNAL(textChanged(QString)), this, SLOT(ecrirePrenom(QString)));
   	QObject::connect(liste, SIGNAL(currentTextChanged(QString)), this, SLOT(ecrireCol(QString)));

	QObject::connect(boutonSuivant, SIGNAL(clicked()), this, SLOT(ouvrirDialogueNewGameVSPlayerSuivant()));
	QObject::connect(boutonSuivant, SIGNAL(clicked()), sousFenetre, SLOT(hide()));
}


void Fenetre::ouvrirDialogueNewGameVSPlayerSuivant()
{
	QWidget *sousFenetre = new QWidget;

	QLineEdit *nom = new QLineEdit;
	QLineEdit *prenom = new QLineEdit;

	QFormLayout *formLayout = new QFormLayout;
	formLayout->addRow("Votre &nom", nom);
	formLayout->addRow("Votre &prenom", prenom);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addLayout(formLayout);

	QPushButton *boutonStart = new QPushButton("Lancer");
	layout->addWidget(boutonStart);

	sousFenetre->setLayout(layout);

	sousFenetre->show();

   	QObject::connect(nom, SIGNAL(textChanged(QString)), this, SLOT(ecrireNom2(QString)));
   	QObject::connect(prenom, SIGNAL(textChanged(QString)), this, SLOT(ecrirePrenom2(QString)));

	QObject::connect(boutonStart, SIGNAL(clicked()), this, SLOT(startGameVSPlayer()));
	QObject::connect(boutonStart, SIGNAL(clicked()), sousFenetre, SLOT(hide()));
}

void Fenetre::startGameVSIA()
{
      std::cout << "bob dans startGameVSIA" << std::endl;

	// création de la partie
	controleur_->jouerContreIA(joueurs_[0].toStdString(), joueurs_[1].toStdString(), joueurs_[2].toStdString());

   // Affichage de l'échiquier   
   plateau_ = new QLabel(this);

      std::cout << "new QLabel" << std::endl;


   QPixmap plat("picture/plateau.png");
   plateau_->setPixmap(plat);
   plateau_->setGeometry(0, 30, 640, 640);
   plateau_->show();

	std::cout << "bob selectionne couleurs" << std::endl;

	if (joueurs_[2].toStdString() == "" || joueurs_[2].toStdString() == "Noir")
	{
		std::cout << "bob noir" << std::endl;
		controleur_->setPartie("echiquierDeBaseN.txt");
	}
	else
	{
		std::cout << "bob blanc" << std::endl;
		controleur_->setPartie("echiquierDeBaseB.txt");
	}

	std::cout << "bob s affiche" << std::endl;

	affichageInitialEchiquier();
}

void Fenetre::startGameVSPlayer()
{
	// création de la partie
	controleur_->jouerContrePlayer(joueurs_[0].toStdString(), joueurs_[1].toStdString(), joueurs_[2].toStdString(), joueurs_[3].toStdString(), joueurs_[4].toStdString());

	std::cout << "bob dans startGameVSPlayer" << std::endl;

	// Affichage de l'échiquier
	plateau_ = new QLabel(this);
	plateau_->setPixmap(QPixmap("picture/plateau.png"));
	plateau_->setGeometry(0, 30, 640, 640);
	plateau_->show();

	std::cout << "bob selectionne couleurs" << std::endl;

	if (joueurs_[2].toStdString() == "Blanc")
	{
		std::cout << "bob blanc" << std::endl;
		controleur_->setPartie("echiquierDeBaseB.txt");
	}
	else
	{
		std::cout << "bob noir" << std::endl;
		controleur_->setPartie("echiquierDeBaseN.txt");
	}

	std::cout << "bob s affiche" << std::endl;

	affichageInitialEchiquier();
}


void Fenetre::affichageInitialEchiquier()
{
   std::cout << "je plante avant l'init" << std::endl;
   for(int i = 0; i < NB_CASES; ++i) {
      for(int j = 0; j < NB_CASES; ++j) {
         cases[i][j] = new PieceCliquable(this, this);
         cases[i][j]->setFixedSize(80,80);
      }
   }

   std::cout << "je plante avant le setPixmap et apres l'init" << std::endl;
   for(int i = 0; i < NB_CASES; ++i) {
      cases[1][i]->setPixmap(QPixmap("picture/pionB.png"));
      cases[6][i]->setPixmap(QPixmap("picture/pionN.png"));
   }

   cases[0][0]->setPixmap(QPixmap("picture/tourB.png"));
   cases[0][1]->setPixmap(QPixmap("picture/cavalierB.png"));
   cases[0][2]->setPixmap(QPixmap("picture/fouB.png"));
   cases[0][3]->setPixmap(QPixmap("picture/reineB.png"));
   cases[0][4]->setPixmap(QPixmap("picture/roiB.png"));
   cases[0][5]->setPixmap(QPixmap("picture/fouB.png"));
   cases[0][6]->setPixmap(QPixmap("picture/cavalierB.png"));
   cases[0][7]->setPixmap(QPixmap("picture/tourB.png"));
   cases[7][0]->setPixmap(QPixmap("picture/tourN.png"));
   cases[7][1]->setPixmap(QPixmap("picture/cavalierN.png"));
   cases[7][2]->setPixmap(QPixmap("picture/fouN.png"));
   cases[7][3]->setPixmap(QPixmap("picture/reineN.png"));
   cases[7][4]->setPixmap(QPixmap("picture/roiN.png"));
   cases[7][5]->setPixmap(QPixmap("picture/fouN.png"));
   cases[7][6]->setPixmap(QPixmap("picture/cavalierN.png"));
   cases[7][7]->setPixmap(QPixmap("picture/tourN.png"));
   std::cout << "je apres  le setPixmap et apres l'init" << std::endl;

	std::shared_ptr<Echiquier> echiquier = controleur_->getEchiquier();
   char type, col;

   int x = 30;
   int y = 5;
	for (int i = 0; i < NB_CASES; ++i)
	{
      y = 5;
		for (int j = 0; j < NB_CASES; ++j)
		{	   
            cases[i][j]->setGeometry(y, x, 80, 80);
			   cases[i][j]->show();
            y += 80;
      }
      x += 80;
   }
   std::cout << "fin affiche" << std::endl;

}

/*
void Fenetre::afficherEchiquier() {
   std::cerr << "Fenetre::afficherEchiquier()" << std::endl;
   std::shared_ptr<Echiquier> echiquier = controleur_->getEchiquier();
   char type, col;
      int x = 32;
      int y = 17;
      QLabel *label = new QLabel(this);
   	for (int i = 0; i < 8; ++i)
   	{
         y = 17;
   		for (int j = 0; j < 8; ++j)
   		{
   			if (echiquier->estOccupee(Coord(i, j)))
   			{
   				type = echiquier->getType(Coord(i, j));
   				col = echiquier->getCouleur(Coord(i, j));

   				switch (type)
   				{
   					case 'P':
   						if (col == 'B')
   							label = (pionB_[j]);
   						else
   							label = (pionN_[j]);
                     break;

   					case 'T':
   						if (col == 'B')
   							label = (tourB_[j/7]);
   						else
   							label = (tourN_[j/7]);
                     break;

   					case 'C':
   						if (col == 'B')
   							label = (cavalierB_[j/6]);
   						else
   							label = (cavalierN_[j/6]);
                     break;

   					case 'F':
   						if (col == 'B')
   							label = (fouB_[j/5]);
   						else
   							label = (fouN_[j/5]);
                     break;

   					case 'D':
   						if (col == 'B')
   							label = (reineB_);
   						else
   							label = (reineN_);
                     break;

   					case 'R':
   						if (col == 'B')
   							label = (roiB_);
   						else
   							label = (roiN_);
                     break;
               }
   		      //label->setGeometry(30 + j*8, i*80, 64, 64);
               label->setGeometry(y, x, 64, 64);
   			   label->show();
               y += 80;
            }
   		}
         x += 80;
   	}
}
*/

void Fenetre::ouvrirMessageAbout()
{
	QMessageBox::about(this, "A propos", "Voici notre jeu d'Echecs.");
}


void Fenetre::ecrireNom(QString n)
{
	joueurs_[0] = n;
	std::cerr << joueurs_[0].toStdString() << std::endl;
}


void Fenetre::ecrirePrenom(QString p)
{
	joueurs_[1] = p;
	std::cerr << joueurs_[1].toStdString() << std::endl;
}


void Fenetre::ecrireCol(QString c)
{
	joueurs_[2] = c;
	std::cerr << joueurs_[2].toStdString() << std::endl;
}


void Fenetre::ecrireNom2(QString n)
{
	joueurs_[3] = n;
	std::cerr << joueurs_[3].toStdString() << std::endl;
}


void Fenetre::ecrirePrenom2(QString p)
{
	joueurs_[4] = p;
	std::cerr << joueurs_[4].toStdString() << std::endl;
}

/*
void Fenetre::mouseReleaseEvent(QMouseEvent *qevent)
{
   QPoint p = qevent->pos();
   std::cerr << "coord du clic : (" << p.x() << "," << p.y() << ")" << std::endl;
   Coord coord( (p.y()-34)/80, p.x()/80 );
      //std::cerr << "Correspond a la case : (" << x  << "," << y << ")" << std::endl;
   if( coord.x < 8 && coord.x >= 0 && coord.y < 8 && coord.y >= 0) {
      std::cerr << "case correcte, clic à gérer\n";
      if ( controleur_->gererClique(coord, clicDepart_->col())) {
         std::cerr << "clic géré et mouvement fait\n";
         clicDepart_->setGeometry(coord.y*80+5,coord.x*80+34,60,60);
         clicDepart_ = nullptr;
      }
   }
}
*/

void Fenetre::cliqueSurPiece(QMouseEvent *qevent, PieceCliquable* piece) 
{
   Coord clic = Coord((piece->y() - 5)/80, (piece->x() - 30)/80);
   std::cerr << "Coord case : " << clic.x << "," << clic.y << std::endl;
   if (!clicPrecedent_ && controleur_->getEchiquier()->estOccupee(clic))
   {
      clicPrecedent_ = piece;
      controleur_->gererClique(clic);
   }
   else
   {
      if (controleur_->gererClique(clic))
      {
         piece->setPixmap(*clicPrecedent_->pixmap());
         clicPrecedent_->setPixmap(QPixmap());
         //clicPrecedent_->repaint();
      }
      clicPrecedent_ = nullptr;
   }


}


/*
   QPoint p;
   if(piece->col() == 'v') {
      std::cerr << "case vide\n";
      p = qevent->pos();
      clicPlateau_ = Coord((p.y()-34)/80, p.x()/80);
   }
   else  {
      std::cerr << "case occupée\n";
      clicPlateau_ = Coord(piece->x(), piece->y());
   }
   std::cerr << "Coord case : " << clicPlateau_.x << "," << clicPlateau_.y << std::endl;
   if(piece) {
      if(piece->col() == 'v') {
         QPoint p = qevent->pos();
         clicPlateau_ = Coord( (p.y()-34)/80, p.x()/80 );
      }

      if(!clicDepart_) {
         std::cerr << "fenetre::cliqueSurPiece : plateau";
         if(piece->col() != 'v') {
   	        clicDepart_ = piece;
		         //std::cerr << "Fenetre::cliqueSurPiece : sélection pièce départ couleur " << piece->col() << std::endl;
               controleur_->gererClique(clicPlateau_, piece->col());
         }
      }
	   else {
	      //std::cerr << "Fenetre::cliqueSurPiece : sélection destination : ";
         if(piece->col() != 'v') clicArrivee_ = piece;
         //std::cerr <<  "gererClique " << clicPlateau_.x << ", " << clicPlateau_.y << " colDepart_ = " << clicDepart_->col() << std::endl;
         if ( controleur_->gererClique(clicPlateau_, clicDepart_->col())) {
            //std::cerr << "Bob set la geometry" << std::endl;
            clicDepart_->setGeometry(clicPlateau_.y*80+5,clicPlateau_.x*80+34,60,60);
         }
         clicDepart_ = nullptr;
         clicArrivee_ = nullptr;
      }
   }
}
*/ 