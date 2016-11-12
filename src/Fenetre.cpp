#include "Fenetre.hpp"

Fenetre::Fenetre(std::shared_ptr<Controleur> controleur) : QWidget()
{
    setFixedSize(800, 800);
 	setWindowIcon(QIcon("picture/logo.png"));
 	setWindowTitle("Echecs");

 	controleur_ = controleur;

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
	QPixmap plateau("picture/plateau.png");
	label->setPixmap(plateau);
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
	QPixmap plateau("picture/plateau.png");
	label->setPixmap(plateau);
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
	QPixmap pionB("picture/pionB.png");
	QPixmap tourB("picture/tourB.png");
	QPixmap cavalierB("picture/cavalierB.png");
	QPixmap fouB("picture/fouB.png");
	QPixmap reineB("picture/reineB.png");
	QPixmap roiB("picture/roiB.png");

	QPixmap pionN("picture/pionN.png");
	QPixmap tourN("picture/tourN.png");
	QPixmap cavalierN("picture/cavalierN.png");
	QPixmap fouN("picture/fouN.png");
	QPixmap reineN("picture/reineN.png");
	QPixmap roiN("picture/roiN.png");

	std::shared_ptr<Echiquier> echiquier = controleur_->getEchiquier();
	char type, col;

	std::cout << "bob dans l'affichage" << std::endl;

	for (int i = 0; i < 8; ++i)
	{
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
							label->setPixmap(pionB);
						else
							label->setPixmap(pionN);
                  break;

					case 'T':
						if (col == 'B')
							label->setPixmap(tourB);
						else
							label->setPixmap(tourN);
                  break;

					case 'C':
						if (col == 'B')
							label->setPixmap(cavalierB);
						else
							label->setPixmap(cavalierN);
                  break;

					case 'F':
						if (col == 'B')
							label->setPixmap(fouB);
						else
							label->setPixmap(fouN);
                  break;

					case 'D':
						if (col == 'B')
							label->setPixmap(reineB);
						else
							label->setPixmap(reineN);
                  break;

					case 'R':
						if (col == 'B')
							label->setPixmap(roiB);
						else
							label->setPixmap(roiN);
                  break;
            }
		      label->setGeometry(30 + j*80, i*80, 64, 64);
			   label->show();
         }
		}
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
