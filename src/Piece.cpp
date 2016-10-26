#include "Piece.hpp"

Piece::Piece(bool etat, char c) : posInitiale_(etat), c_(c) {}

Piece::~Piece() {}

char Piece::getCouleur() { return c_; }

bool Piece::pieceEnPosInit() { return posInitiale_; }

void Piece::setPosInitiale(bool posInit) { posInitiale_ = posInit; }

bool Piece::roquer(Coord dep, Coord but, Echiquier *e) { return false; }
