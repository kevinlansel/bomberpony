//
// Explosion.cpp for Explosion in /home/haz3/projet/bomberpony/testgdl
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Wed May 22 12:44:23 2013 Maxime Wojciak
// Last update Thu May 23 17:50:41 2013 Maxime Wojciak
//

#include	"Explosion.hpp"

Explosion::Explosion(const Vector3f &coord, unsigned int xplosize) : _Xplosize(xplosize) {

}

Explosion::~Explosion() {

}

void		Explosion::initialize() {
  for (int tmp = 4 * this->_Xplosize + 1; tmp > 0; tmp--)
    {
      gdl::Model toto = gdl::Model::load("./marvin.fbx");
      this->_explosion.push_back(toto);
    }
  for (int tmp = 4 * this->_Xplosize +1 ; tmp > 0; tmp--)
    this->_coord.push_back(Vector3f(0, 0, 100 * tmp));
}

void		Explosion::update(gdl::GameClock &_clock) {
  std::list<gdl::Model>::iterator it = this->_explosion.begin();
  for (; it != this->_explosion.end(); ++it) {
    it->update(_clock);
  }
}

void		Explosion::draw() {
  std::list<gdl::Model>::iterator it = this->_explosion.begin();
  std::list<Vector3f>::iterator it_vector = this->_coord.begin();
  for (; it != this->_explosion.end(); ++it, ++it_vector) {
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
      glTranslatef(it_vector->x, it_vector->y, it_vector->z);
    it->draw();
    glPopMatrix();
  }
}

void		Explosion::unload(void) {

}
