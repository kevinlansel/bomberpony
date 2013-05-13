//
// Menu.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Wed May  8 17:58:43 2013 florian dewulf
// Last update Mon May 13 14:36:59 2013 florian dewulf
//

#include	"Menu.hpp"

Menu::Menu(const Vector3f &vec, const Vector3f &pt) : Scene(vec, pt), _background(NULL), _cursor(Vector3f(20, -10, 0), Vector3f(40, 0, 0), Vector3f(20, 10, 0), Vector3f(1.0, 1.0, 1.0))
{
}

Menu::~Menu()
{
  delete this->_background;
}

void		Menu::initialize(const std::string &texture)
{
  this->_background = new Cube(Vector3f(-400, 300, -10), Vector3f(400, -300, -11), texture);
  this->_camera.initialize(1024, 768, this->getPoscam(), this->getTarget(), 0);
  this->_cursor.initialize();
  this->_txt.setSize(70);
  this->_txt.setFont("./ressource/Bender-Inline.otf");
}

void		Menu::update(gdl::GameClock &gameClock_, gdl::Input &input)
{
  Vector3f	tmp(this->_cursor.getTranslation());

  this->_camera.update(gameClock_, input);
  this->_background->update(gameClock_, input);
  this->_cursor.update(gameClock_, input);
  if (input.isKeyDown(gdl::Keys::Down))
    this->_cursor.setTranslation(Vector3f(tmp.x, tmp.y - 20, tmp.z));
  else if (input.isKeyDown(gdl::Keys::Up))
    this->_cursor.setTranslation(Vector3f(tmp.x, tmp.y + 20, tmp.z));
}

void		Menu::draw()
{
  this->_camera.draw();
  this->_background->draw();
  this->_cursor.draw();
  this->_txt.draw();
}

