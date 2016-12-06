#include "Fenetre.hpp"

Fenetre::Fenetre(std::shared_ptr<Controleur> controleur) : QWidget(), clicDepart_(nullptr), clicArrivee_(nullptr), controleur_(controleur)
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


    QObject::connect(this, SIGNAL(mouvementEffectue()), this, SLOT(afficherEchiquier()));
}

Fenetre::~Fenetre() {
   for(int i = 0; i < NB_PIONS; ++i) {
      delete pionB_[i];
      delete pionN_[i];
   }
   for(int i = 0; i < NB_ATOUTS; ++i) {
      delete cavalierB_[i];
      delete cavalierN_[i];
      delete fouB_[i];
      delete fouN_[i];
      delete tourB_[i];
      delete tourN_[i];
   }
   delete roiB_;
   delete roiN_;
   delete reineB_;
   delete reineN_;
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
	// création de la partie
	controleur_->jouerContreIA(joueurs_[0].toStdString(), joueurs_[1].toStdString(), joueurs_[2].toStdString());

	std::cout << "bob dans startGameVSIA" << std::endl;

	// Affichage de l'échiquier
	QLabel *label = new QLabel(this);
	QPixmap plateau_("picture/plateau.png");
	label->setPixmap(plateau_);
	label->setGeometry(0, 30, 640, 640);
	label->show();

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
	QLabel *label = new QLabel(this);
	QPixmap plateau_("picture/plateau.png");
	label->setPixmap(plateau_);
	label->setGeometry(0, 30, 640, 640);
	label->show();

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
   for(int i = 0; i < 8; ++i) {
      pionB_[i] = new PieceCliquable(this,this,'B');
      pionB_[i]->setPixmap(QPixmap("picture/pionB.png"));
      pionN_[i] = new PieceCliquable(this,this,'N');
      pionN_[i]->setPixmap(QPixmap("picture/pionN.png"));
   }

   for(int i = 0; i < 2; ++i) {
      tourB_[i] = new PieceCliquable(this,this,'B');
	   tourB_[i]->setPixmap(QPixmap("picture/tourB.png"));
      tourN_[i] = new PieceCliquable(this,this,'N');
      tourN_[i]->setPixmap(QPixmap("picture/tourN.png"));
      cavalierN_[i] = new PieceCliquable(this,this,'N');
      cavalierN_[i]->setPixmap(QPixmap("picture/cavalierN.png"));
      cavalierB_[i] = new PieceCliquable(this,this,'B');
	   cavalierB_[i]->setPixmap(QPixmap("picture/cavalierB.png"));
      fouB_[i] = new PieceCliquable(this,this,'B');
	   fouB_[i]->setPixmap(QPixmap("picture/fouB.png"));
      fouN_[i] = new PieceCliquable(this,this,'N');
      fouN_[i]->setPixmap(QPixmap("picture/fouN.png"));
   }
   reineB_ = new PieceCliquable(this,this,'B');
	reineB_->setPixmap(QPixmap("picture/reineB.png"));
   roiB_ = new PieceCliquable(this,this,'B');
	roiB_->setPixmap(QPixmap("picture/roiB.png"));

   reineN_ = new PieceCliquable(this,this,'N');
   reineN_->setPixmap(QPixmap("picture/reineN.png"));
   roiN_ = new PieceCliquable(this,this,'N');
   roiN_->setPixmap(QPixmap("picture/roiN.png"));

	std::shared_ptr<Echiquier> echiquier = controleur_->getEchiquier();
   char type, col;

	std::cout << "bob dans l'affichage" << std::endl;

   int x = 30;
   int y = 5;
	for (int i = 0; i < 8; ++i)
	{
      y = 5;
		for (int j = 0; j < 8; ++j)
		{
			if (echiquier->estOccupee(Coord(i, j)))
			{
				type = echiquier->getType(Coord(i, j));
				col = echiquier->getCouleur(Coord(i, j));
				QLabel *label = new QLabel(this);

            std::cerr << "En (" << i << "," << j << ") : " << type << " de couleur " << col << std::endl;
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
   clicDepart_ = nullptr;
   clicArrivee_ = nullptr;
}

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


void Fenetre::mouseReleaseEvent(QMouseEvent *qevent)
{
   	QPoint p = qevent->pos();
   	std::cerr << "coord du clic : (" << p.x() << "," << p.y() << ")" << std::endl;
   	Coord coord( (p.y()-34)/80, p.x()/80 );
   	//std::cerr << "Correspond a la case : (" << x  << "," << y << ")" << std::endl;
  
  	if( coord.x < 8 && coord.x >= 0 && coord.y < 8 && coord.y >= 0) 
   	{
      	std::cerr << "case correcte, clic à gérer\n";
     
      	if ( controleur_->gererClique(coord, clicDepart_->col())) 
      	{
        	std::cerr << "clic géré et mouvement fait\n";
        	clicDepart_->setGeometry(coord.y*80 + 5, coord.x*80 + 34, 60, 60);
       		clicDepart_ = nullptr;
     	}	
   	}
}


void Fenetre::cliqueSurPiece(PieceCliquable* piece) 
{
   	if(piece) 
   	{
   		if(!clicDepart_) 
   		{	
			clicDepart_ = piece;
			std::cerr << "Fenetre::cliqueSurPiece : sélection pièce départ" << std::endl;
		}
		else 
		{
			std::cerr << "Fenetre::cliqueSurPiece : sélection destination : ";
    	  	clicArrivee_ = piece;
		}
	}
}
