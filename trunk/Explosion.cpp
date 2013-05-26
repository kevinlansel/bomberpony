//
// Explosion.cpp for Explosion in /home/haz3/projet/bomberpony/testgdl
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Wed May 22 12:44:23 2013 Maxime Wojciak
// Last update Sun May 26 02:28:56 2013 florian dewulf
//

#include	"Explosion.hpp"

Explosion::Explosion(const Vector3f &coord, unsigned int xplosize) : _time(0), _BombPos(coord), _Xplosize(xplosize) {

}

Explosion::~Explosion() {

}

void		Explosion::initialize() {
  Vector3f	posx(this->_BombPos.x - this->_Xplosize * 300, 300, this->_BombPos.z);
  Vector3f	posz(this->_BombPos.x, 300, this->_BombPos.z - this->_Xplosize * 300);

  for (unsigned int tmp = this->_Xplosize * 2 + 1 ; tmp > 0; tmp--)
    {
      if (tmp != this->_Xplosize + 1)
	this->_explosion.push_back(new Rectangle(posz, Vector3f(posz.x + 300, 0, posz.z + 300), "./ressource/explosion.png"));
      this->_explosion.push_back(new Rectangle(posx, Vector3f(posx.x + 300, 0, posx.z + 300), "./ressource/explosion.png"));
      posz.z += 300;
      posx.x += 300;
    }
}

bool		Explosion::update(gdl::GameClock &_clock) {
  if (this->_time == 0)
    this->_time = _clock.getTotalGameTime();
  if (this->_time + 2 < _clock.getTotalGameTime())
    return false;
  return true;
}

void		Explosion::draw() {
  for (std::list<Rectangle *>::iterator it = this->_explosion.begin() ; it != this->_explosion.end() ; ++it)
    (*it)->draw();
    /*
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
      glTranslatef(it_vector->x, it_vector->y, it_vector->z);
    it->draw();
    glPopMatrix();
    */
}
