//
// Menu.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Wed May  8 17:58:43 2013 florian dewulf
// Last update Thu May  9 15:12:27 2013 florian dewulf
//

#include	"Menu.hpp"

Menu::Menu(const Vector3f &vec, const Vector3f &pt) : Scene(vec, pt)
{
}

Menu::~Menu()
{
}

void		Menu::initialize(const std::string &model)
{
  this->_background = gdl::Model::load(model);
  this->_background.infos();
  //this->_txt.setSize(20);
}

void		Menu::update(gdl::GameClock &gameClock_)
{
  this->_background.update(gameClock_);
  this->_background.play("Take 001");
}

void		Menu::draw()
{
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(0.0, 0.0, 0.0);
  this->_background.draw();
  glPopMatrix();
  //  this->_background.draw();
  //this->_txt.draw();
}

