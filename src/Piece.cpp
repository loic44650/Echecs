#include "Piece.hpp"

Piece::Piece(int id, bool etat, char c) : identifiant_(id), posInitiale_(etat), c_(c) {}

Piece::~Piece() {}

char Piece::getCouleur() { return c_; }

bool Piece::pieceEnPosInit() { return posInitiale_; }

void Piece::setPosInitiale(bool posInit) { posInitiale_ = posInit; }

//char Piece::afficher() {}
