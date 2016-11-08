/**
 * @file utils.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 5 oct. 2016
 * @brief Fichier header contenant des facilities
**/


#pragma once


#include <string>

struct Coord {
   int x;
   int y;

   Coord() { x=0; y=0; }

   Coord(int a, int b) { x=a; y=b; }

   Coord(std::string str)
   {
		if ((8 - (str[0] - '0')) >= 0 && (8 - (str[0] - '0')) <= 7)
		{
			x = (8 - (str[0] - '0'));
		}
		else if ((8 - (str[1] - '0')) >= 0 && (8 - (str[1] - '0')) <= 7)
		{
			x = (8 - (str[1] - '0'));
		}
		if (str[0] >= 'A' && str[0] <='H')
		{
			y = str[0] - 'A';
		}
		else if (str[1] >= 'A' && str[1] <= 'H')
		{
			y = str[1] - 'A';
		}
	}

   void getCoord(std::string str)
	{
		if ((8 - (str[0] - '0')) >= 0 && (8 - (str[0] - '0')) <= 7)
		{
			x = (8 - (str[0] - '0'));
		}
		else if ((8 - (str[1] - '0')) >= 0 && (8 - (str[1] - '0')) <= 7)
		{
			x = (8 - (str[1] - '0'));
		}
		if (str[0] >= 'A' && str[0] <='H')
		{
			y = str[0] - 'A';
		}
		else if (str[1] >= 'A' && str[1] <= 'H')
		{
			y = str[1] - 'A';
		}
	}

   std::string toString() {
      std::string res = '('+ std::to_string(x) + ',' + std::to_string(y) +')';
      return res;
   }

   inline bool operator==(const Coord b) { return ( this->x == b.x && this->y == b.y ); }
   bool operator=(const Coord b) { this->x = b.x; this->y = b.y; }
};


struct Coup {
   Coord dep;
   Coord but;

   Coup(Coord a, Coord b) { dep = a; but = b; }
};
