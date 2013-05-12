//
// Menu.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Wed May  8 17:58:43 2013 florian dewulf
// Last update Sun May 12 19:06:59 2013 florian dewulf
//

#include	"Menu.hpp"

Menu::Menu(const Vector3f &vec, const Vector3f &pt) : Scene(vec, pt), _background(NULL), _cursor(Vector3f(0, 0, 0), Vector3f(20, 20, 20), Vector3f(20, -20, 20), Vector3f(1.0, 1.0, 1.0))
{
}

Menu::~Menu()
{
  delete this->_background;
}

void		Menu::initialize(const std::string &texture)
{
  this->_background = new Cube(Vector3f(-400, 300, 0), Vector3f(400, -300, 1), texture);
  this->_camera.initialize(1024, 768, this->getPoscam(), this->getTarget(), 0);
  this->_txt.setSize(70);
  this->_txt.setFont("./ressource/Bender-Inline.otf");
}

void		Menu::update(gdl::GameClock &gameClock_, gdl::Input &input)
{
  this->_camera.update(gameClock_, input);
  this->_background->update(gameClock_, input);
}

void		Menu::draw()
{
  this->_camera.draw();
  this->_background->draw();
  this->_txt.draw();
}

