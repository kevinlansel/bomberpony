//
// Bombe.cpp for Bombe in /home/haz3/projet/bomberpony
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Mon May 13 10:55:07 2013 Maxime Wojciak
// Last update Thu May 23 16:15:34 2013 Maxime Wojciak
//

#include	"Bombe.hpp"

Bombe::Bombe(const Vector3f &coord) : _translation(coord) {
  this->_clignote = false;
}

Bombe::~Bombe() {
}

void		Bombe::setCoord(Vector3f coord) {
  this->_translation = coord;
}

Vector3f	Bombe::getCoord() {
  return this->_translation;
}

/*
** Init du model 3D.
*/

void		Bombe::initialize(gdl::GameClock &_clock) {
  this->_BombeModel = gdl::Model::load("./bomb.fbx");
  this->BombeTempo = _clock.getTotalGameTime();
}

/*
** Place la bombe en x et y.
** Update de la bombe.
*/

bool		Bombe::update(gdl::GameClock &_clock) {
  this->_BombeModel.update(_clock);
  this->_BombeModel.play("Take 001");
  this->_BombeModel.update(_clock);
  glTranslatef(-this->_translation.x, -this->_translation.y, -this->_translation.z);
  //glTranslatef(this->_translation.x, this->_translation.y, this->_translation.z);
  //glTranslatef(-this->_translation.x, -this->_translation.y, -this->_translation.z);
  //glTranslatef(this->_translation.x, this->_translation.y, this->_translation.z);
  if (this->_clignote == false && _clock.getTotalGameTime() - this->BombeTempo > 2 && _clock.getTotalGameTime() - this->BombeTempo < 4)
    this->_clignote = true;
  if (_clock.getTotalGameTime() - this->BombeTempo >= 4)
  {
    this->_clignote = false;
    return true;
  }
  return false;
}

/*
** Affiche LA bombe au X et Y
*/

void		Bombe::draw() {
  static int	prout = 1;

  glTranslatef(this->_translation.x, this->_translation.y, this->_translation.z);
  if (this->_clignote && prout == 100)
  {
    std::cout << "if" << std::endl;
    prout = 0;
  }
  else if (this->_clignote && prout > 70)
  {
    std::cout << "else if" << std::endl;
    prout++;
  }
  else
  {
    if (this->_clignote && prout <= 70)
      prout++;
    std::cout << "else" << std::endl;
    this->_BombeModel.draw();
  }
  //  sleep(4);
}

void		Bombe::unload() {

}
