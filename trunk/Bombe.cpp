//
// Bombe.cpp for Bombe in /home/haz3/projet/bomberpony
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Mon May 13 10:55:07 2013 Maxime Wojciak
// Last update Wed May 15 15:42:32 2013 Maxime Wojciak
//

#include	"Bombe.hpp"

Bombe::Bombe() {

}

Bombe::~Bombe() {
}

void		Bombe::setCoord(Vector3f coord) {
  this->_coord = coord;
}

Vector3f	Bombe::getCoord() {
  return this->_coord;
}

/*
** Affiche une bombe au X et Y
** puis après le temps (a definir)
** affiche explosion de la bombe
*/

void		Bombe::Draw() {
}

void		Bombe::DropBombe(Vector3f coord, const gdl::GameClock &gameClock) {
  std::cout << this->_coord.x << std::endl;
  std::cout << this->_coord.y << std::endl;
  std::cout << this->_coord.z << std::endl;

  //affiche une bombe au X et Y, puis après le temps affiche explosion de la bombe
}
