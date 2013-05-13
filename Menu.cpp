//
// Menu.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Wed May  8 17:58:43 2013 florian dewulf
// Last update Mon May 13 22:45:30 2013 florian dewulf
//

#include	"Menu.hpp"

Menu::Menu(const Vector3f &vec, const Vector3f &pt, MenuType choice) : Scene(vec, pt), _background(NULL), _cursor(Vector3f(20, -10, 0), Vector3f(40, 0, 0), Vector3f(20, 10, 0), Vector3f(1.0, 1.0, 1.0)), _choice(choice)
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
  this->_cursor.setTranslation(Vector3f(40, 52, 0));
  this->_txt.setFont("./ressource/Bender-Inline.otf");
}

void		Menu::update(gdl::GameClock &gameClock_, gdl::Input &input)
{
  static float	tempo = -1;

  if (tempo == -1)
    tempo = gameClock_.getTotalGameTime();
  this->_camera.update(gameClock_, input);
  this->_background->update(gameClock_, input);
  this->_cursor.update(gameClock_, input);
  tempo = this->move(tempo, gameClock_, input);
}

void		Menu::draw()
{
  this->_camera.draw();
  this->_background->draw();
  this->_cursor.draw();
  this->_txt.draw();
}

float		Menu::move(float tempo, gdl::GameClock &gameClock_, gdl::Input &input)
{
  Vector3f	tmp(this->_cursor.getTranslation());

  if (tempo + 0.2 < gameClock_.getTotalGameTime())
    {
      if (input.isKeyDown(gdl::Keys::Down))
	{
	  this->_cursor.setTranslation(Vector3f(tmp.x, tmp.y - 70, tmp.z));
	  tempo = gameClock_.getTotalGameTime();
	  this->_choice++;
	  if (this->_choice == 4)
	    {
	      this->_choice = 0;
	      this->_cursor.setTranslation(Vector3f(40, 52, 0));
	    }
	}
      else if (input.isKeyDown(gdl::Keys::Up))
	{
	  this->_cursor.setTranslation(Vector3f(40, 262, 0));
	  tempo = gameClock_.getTotalGameTime();
	  this->_choice--;
	  if (this->_choice == -1)
	    this->_choice = 3;
	}
    }
  return (tempo);
}

MenuType	Menu::getChoice() const
{
  return this->_choice;
}
