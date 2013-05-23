//
// Explosion.cpp for Explosion in /home/haz3/projet/bomberpony/testgdl
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Wed May 22 12:44:23 2013 Maxime Wojciak
// Last update Thu May 23 16:29:19 2013 Maxime Wojciak
//

#include	"Explosion.hpp"

Explosion::Explosion(const Vector3f &coord, unsigned int xplosize) : _coord(coord), _Xplosize(xplosize) {

}

Explosion::~Explosion() {

}

void		Explosion::initialize() {
  for (int tmp = 4 * this->_Xplosize + 1; tmp > 0; tmp--)
    this->_explosion.push_back(gdl::Model::load("./marvin.fbx"));
}

void		Explosion::update(gdl::GameClock &_clock) {
  std::list<gdl::Model>::iterator it = this->_explosion.begin();
  for (; it != this->_explosion.end(); ++it) {
    it->update(_clock);
  }
}

void		Explosion::draw() {
  std::list<gdl::Model>::iterator it = this->_explosion.begin();
  for (; it != this->_explosion.end(); ++it) {
    std::cout << "cocu" << std::endl;
    //glTranslatef(this->_coord.x, this->_coord.y, this->_coord.z);
    it->draw();
  }
}

void		Explosion::unload(void) {

}
