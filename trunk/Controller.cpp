//
// Controller.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 15:52:40 2013 florian dewulf
// Last update Mon May 13 17:00:50 2013 florian dewulf
//

#include	"Controller.hpp"

Controller::Controller() : _scene(new Menu(Vector3f(0, 0, 5000), Vector3f(0, 0, 0), MENU)), _sound(true), _map_choice(true), _map_option(""), _screen(MENU)
{
}

Controller::~Controller()
{
}

void		Controller::initialize()
{
  this->_scene->initialize("./ressource/background.png");
  this->_scene->setColor(255, 255, 255);
  this->_scene->setTxt("  Play\nOption\nLadder\n  Exit\n", 500, 200);
}

void		Controller::Majmap()
{
  File		f;

  if (f.getStatemap())
    this->_map = f.ls();
}

void		Controller::Majscore()
{
}

void		Controller::update(gdl::GameClock &clock, gdl::Input &input)
{
  this->_scene->update(clock, input);
  if (dynamic_cast<Menu *>(this->_scene))
    this->_screen = reinterpret_cast<Menu *>(this->_scene)->getChoice();
}

void		Controller::draw()
{
  this->_scene->draw();
}

void		Controller::changeScene(const Vector3f &pos, const Vector3f &target, MenuType type)
{
  if (this->_scene)
    delete this->_scene;
  if (type == MENU || type == GAME || type == SCORE || type == OPTION)
    this->_scene = new Menu(Vector3f(0, 0, 2000), Vector3f(0, 0, 0), type);
  else if (type == BATTLE)
    ;//game
  else
    ;//load écran de victoire ou fail
  this->_screen = type;
}
