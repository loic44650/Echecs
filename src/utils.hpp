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

   inline bool operator==(const Coord b) { return ( this->x == b.x && this->y == b.y ); }
};


#endif
