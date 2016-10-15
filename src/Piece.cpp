#include "Piece.hpp"

Piece::Piece(int id, bool etat, char c) : identifiant_(id), statut_(etat), c_(c) {}

Piece::~Piece() {}

char Piece::getCouleur() { return c_; }

//char Piece::afficher() {}
