#include "Piece.hpp"

Piece::Piece(int id, bool etat, char c) : identifiant_(id), posInitiale_(etat), c_(c) {}

Piece::~Piece() {}

char Piece::getCouleur() { return c_; }

bool Piece::pieceEnPosInit() { return posInitiale_; }

void Piece::setPosInitiale(bool posInit) { posInitiale_ = posInit; }

bool Piece::roque(Coord dep, Coord but, Echiquier *e) { return false; } 

//char Piece::afficher() {}
