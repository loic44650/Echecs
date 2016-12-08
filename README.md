# Echecs

Commandes de compilation (si Makefile non présent dans le dossier) :

	qmake -project "CONFIG += c++11
					QT += widgets"
	# Ou rajouter les deux lignes entre guillemets dans le fichier Echecs.pro
	qmake
	make

Commandes de compilation (si Makefile présent dans le dossier) :

	make

Commande d'exécution :

	./Echecs