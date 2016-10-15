/**
 * @file utils.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 5 oct. 2016
 * @brief Fichier header contenant des facilities
**/

#ifndef UTILS_HPP
#define UTILS_HPP

struct Coord {
   int x;
   int y;

   Coord() { x=0; y=0; }
   Coord(int a, int b) { x=a; y=b; }
   inline bool operator==(const Coord b) { return ( this->x == b.x && this->y == b.y ); }
};


#endif
