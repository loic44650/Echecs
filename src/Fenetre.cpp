#include "Fenetre.hpp"

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
Fenetre::Fenetre(std::shared_ptr<Controleur> controleur) : QWidget(), controleur_(controleur)
{
	setFixedSize(800, 800);
	setWindowIcon(QIcon("picture/logo.png"));
	setWindowTitle("Echecs");

	clicPrecedent_ = nullptr;

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

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
Fenetre::~Fenetre() {/*
	for(int i = 0; i < NB_CASES; ++i) {
		for(int j = 0; j < NB_CASES; ++j)
		delete cases[i][j];
	}
		delete plateau_;*/
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
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

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
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

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
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

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Fenetre::startGameVSIA()
{
	controleur_->jouerContreIA(joueurs_[0].toStdString(), joueurs_[1].toStdString(), joueurs_[2].toStdString());
   
	plateau_ = new QLabel(this);

	QPixmap plat("picture/plateau.png");
	plateau_->setPixmap(plat);
	plateau_->setGeometry(0, 30, 640, 640);
	plateau_->show();

	if (joueurs_[2].toStdString() == "" || joueurs_[2].toStdString() == "Noir")
	{
		controleur_->setPartie("echiquierDeBaseN.txt");
	}
	else
	{
		controleur_->setPartie("echiquierDeBaseB.txt");
	}

	affichageInitialEchiquier();
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Fenetre::startGameVSPlayer()
{
	controleur_->jouerContrePlayer(joueurs_[0].toStdString(), joueurs_[1].toStdString(), joueurs_[2].toStdString(), joueurs_[3].toStdString(), joueurs_[4].toStdString());

	plateau_ = new QLabel(this);
	plateau_->setPixmap(QPixmap("picture/plateau.png"));
	plateau_->setGeometry(0, 30, 640, 640);
	plateau_->show();

	if (joueurs_[2].toStdString() == "" || joueurs_[2].toStdString() == "Noir")
	{
		controleur_->setPartie("echiquierDeBaseN.txt");
	}
	else
	{
		controleur_->setPartie("echiquierDeBaseB.txt");
	}

	affichageInitialEchiquier();
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Fenetre::affichageInitialEchiquier()
{
	int ligneB, ligneN, lignePB, lignePN;

	if (joueurs_[2].toStdString() == "Blanc")
	{
	
		ligneB = 7;
		lignePB = 6;
		ligneN = 0;
		lignePN = 1;
	}
	else 
	{
		ligneB = 0;
		lignePB = 1;
		ligneN = 7;
		lignePN = 6;
	}

	for(int i = 0; i < NB_CASES; ++i) 
	{
		for(int j = 0; j < NB_CASES; ++j) 
		{
			cases[i][j] = new PieceCliquable(this, this);
			cases[i][j]->setFixedSize(80,80);
		}
	}

	for(int i = 0; i < NB_CASES; ++i) 
	{
		cases[lignePB][i]->setPixmap(QPixmap("picture/pionB.png"));
		cases[lignePN][i]->setPixmap(QPixmap("picture/pionN.png"));
	}

	cases[ligneB][0]->setPixmap(QPixmap("picture/tourB.png"));
	cases[ligneB][1]->setPixmap(QPixmap("picture/cavalierB.png"));
	cases[ligneB][2]->setPixmap(QPixmap("picture/fouB.png"));
	cases[ligneB][3]->setPixmap(QPixmap("picture/reineB.png"));
	cases[ligneB][4]->setPixmap(QPixmap("picture/roiB.png"));
	cases[ligneB][5]->setPixmap(QPixmap("picture/fouB.png"));
	cases[ligneB][6]->setPixmap(QPixmap("picture/cavalierB.png"));
	cases[ligneB][7]->setPixmap(QPixmap("picture/tourB.png"));
	cases[ligneN][0]->setPixmap(QPixmap("picture/tourN.png"));
	cases[ligneN][1]->setPixmap(QPixmap("picture/cavalierN.png"));
	cases[ligneN][2]->setPixmap(QPixmap("picture/fouN.png"));
	cases[ligneN][3]->setPixmap(QPixmap("picture/reineN.png"));
	cases[ligneN][4]->setPixmap(QPixmap("picture/roiN.png"));
	cases[ligneN][5]->setPixmap(QPixmap("picture/fouN.png"));
	cases[ligneN][6]->setPixmap(QPixmap("picture/cavalierN.png"));
	cases[ligneN][7]->setPixmap(QPixmap("picture/tourN.png"));
	

	std::shared_ptr<Echiquier> echiquier = controleur_->getEchiquier();

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
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Fenetre::ouvrirMessageAbout()
{
	QMessageBox::about(this, "A propos", "Voici notre jeu d'Echecs.");
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Fenetre::ecrireNom(QString n)
{
	joueurs_[0] = n;
	std::cerr << joueurs_[0].toStdString() << std::endl;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Fenetre::ecrirePrenom(QString p)
{
	joueurs_[1] = p;
	std::cerr << joueurs_[1].toStdString() << std::endl;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Fenetre::ecrireCol(QString c)
{
	joueurs_[2] = c;
	std::cerr << joueurs_[2].toStdString() << std::endl;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Fenetre::ecrireNom2(QString n)
{
	joueurs_[3] = n;
	std::cerr << joueurs_[3].toStdString() << std::endl;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Fenetre::ecrirePrenom2(QString p)
{
	joueurs_[4] = p;
	std::cerr << joueurs_[4].toStdString() << std::endl;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Fenetre::cliqueSurPiece(PieceCliquable* piece) 
{
	Coord clic = Coord(piece->y()/80, piece->x()/80);

	if (!clicPrecedent_ && controleur_->getEchiquier()->estOccupee(clic))
	{
		clicPrecedent_ = piece;
		controleur_->gererClique(clic);
	}
	else if (clicPrecedent_)
	{
		if (controleur_->gererClique(clic))
		{
			piece->setPixmap(*clicPrecedent_->pixmap());
			clicPrecedent_->setPixmap(QPixmap());
		}
		clicPrecedent_ = nullptr;
	}
}