//
// Menu.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Wed May  8 17:58:43 2013 florian dewulf
// Last update Wed May 15 16:59:39 2013 florian dewulf
//

#include	"Menu.hpp"

Menu::Menu(const Vector3f &vec, const Vector3f &pt, MenuType choice, const std::vector<int> &limit) : Scene(vec, pt), _background(NULL), _cursor(Vector3f(20, -10, 0), Vector3f(40, 0, 0), Vector3f(20, 10, 0), Vector3f(1.0, 1.0, 1.0)), _choice(1), _list(limit)
{
}

Menu::~Menu()
{
  delete this->_background;
}

void		Menu::initialize(const std::string &texture, const Vector3f &limit_up, const Vector3f &limit_down)
{
  this->_background = new Cube(Vector3f(-400, 300, -10), Vector3f(400, -300, -11), texture);
  this->_camera.initialize(1024, 768, this->getPoscam(), this->getTarget(), 0);
  this->_cursor.initialize();
  this->_txt.setSize(65);
  this->_cursor.setTranslation(Vector3f(40, 52, 0));
  this->_txt.setFont("./ressource/Bender-Inline.otf");
  this->_limit_up = limit_up;
  this->_limit_down = limit_down;
}

MenuType	Menu::update(gdl::GameClock &gameClock_, gdl::Input &input)
{
  static float	tempo = -1;

  if (tempo == -1)
    tempo = gameClock_.getTotalGameTime();
  this->_camera.update();
  this->_background->update();
  this->_cursor.update();
  this->move(tempo, gameClock_, input);
  if (tempo + 0.2 < gameClock_.getTotalGameTime() && input.isKeyDown(gdl::Keys::Return))
    {
      tempo = gameClock_.getTotalGameTime();
      std::cout << this->_list[this->_choice] << std::endl;
      return this->_list[this->_choice];
    }
  return NOTHING;
}

void		Menu::draw()
{
  this->_camera.draw();
  this->_background->draw();
  this->_cursor.draw();
  this->_txt.draw();
}

void		Menu::move(float &tempo, gdl::GameClock &gameClock_, gdl::Input &input)
{
  Vector3f	tmp(this->_cursor.getTranslation());

  if (tempo + 0.2 < gameClock_.getTotalGameTime())
    {
      if (input.isKeyDown(gdl::Keys::Down))
	{
	  this->_cursor.setTranslation(Vector3f(tmp.x, tmp.y - 65, tmp.z));
	  tempo = gameClock_.getTotalGameTime();
	  this->inc_choice();
	}
      else if (input.isKeyDown(gdl::Keys::Up))
	{
	  this->_cursor.setTranslation(Vector3f(tmp.x, tmp.y + 65, tmp.z));
	  tempo = gameClock_.getTotalGameTime();
	  this->dec_choice();
	}
    }
}

MenuType	Menu::getChoice() const
{
  std::cout << "Choice : " << this->_choice << std::endl;
  return this->_list[this->_choice];
}

void		Menu::inc_choice()
{
  this->_choice++;
  if (this->_choice == this->_list[0])
    {
      this->_choice = 1;
      this->_cursor.setTranslation(this->_limit_up);
    }
}

void		Menu::dec_choice()
{
  this->_choice--;
  if (this->_choice == 0)
    {
      this->_choice = this->_list[0] - 1;
      this->_cursor.setTranslation(this->_limit_down);
    }
}
