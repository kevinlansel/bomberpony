//
// Bombe.cpp for Bombe in /home/haz3/projet/bomberpony
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Mon May 13 10:55:07 2013 Maxime Wojciak
// Last update Wed May 22 13:30:59 2013 Maxime Wojciak
//

#include	"Bombe.hpp"

Bombe::Bombe() {
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

void		Bombe::initialize(void) {
  this->_BombeModel = gdl::Model::load("./bomb.fbx");
}

/*
** Place la bombe en x et y.
** Update de la bombe.
*/

void		Bombe::update(gdl::GameClock &_clock, gdl::Input &input) {
  this->_BombeModel.update(_clock);
  this->_BombeModel.play("Take 001");
  this->_BombeModel.update(_clock);
  if (input.isKeyDown(gdl::Keys::Right) == true)
  {
    glTranslatef(-this->_translation.x, -this->_translation.y, -this->_translation.z);
    this->_translation.x = (_translation.x + 1);
    glTranslatef(this->_translation.x, this->_translation.y, this->_translation.z);
  }
  if (input.isKeyDown(gdl::Keys::Left) == true)
  {
    glTranslatef(-this->_translation.x, -this->_translation.y, -this->_translation.z);
    this->_translation.x = (_translation.x - 1);
    glTranslatef(this->_translation.x, this->_translation.y, this->_translation.z);
  }
}

/*
** Affiche LA bombe au X et Y
*/

void		Bombe::draw() {
  this->_BombeModel.draw();
//  sleep(4);
}

void		Bombe::unload() {

}
