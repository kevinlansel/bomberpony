//
// Menu.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Wed May  8 17:58:43 2013 florian dewulf
// Last update Sun May 26 01:57:43 2013 florian dewulf
//

#include	"Menu.hpp"

Menu::Menu(const Vector3f &vec, const Vector3f &pt, MenuType choice, const std::vector<int> &limit) : Scene(vec, pt), _background(NULL), _cursor(Vector3f(20, -10, 0), Vector3f(40, 0, 0), Vector3f(20, 10, 0), Vector3f(1.0, 1.0, 1.0)), _choice(1), _list(limit), _snd_move("./ressource/Cursor Move.wav"), _snd_enter("./ressource/menu_click.wav")
{
}

Menu::~Menu()
{
  delete this->_background;
}

void		Menu::initialize(const std::string &texture, const Vector3f &limit_up, const Vector3f &limit_down)
{
  //if option => check map list
  //if score => check score file
  this->_background = new Rectangle(Vector3f(-400, 300, -10), Vector3f(400, -300, -10), texture);
  this->_camera.initialize(1024, 768, this->getPoscam(), this->getTarget(), 0);
  this->_cursor.initialize();
  this->_txt.setSize(65);
  this->_cursor.setTranslation(Vector3f(40, 52, 0));
  this->_txt.setFont("./ressource/Bender-Inline.otf");
  this->_limit_up = limit_up;
  this->_limit_down = limit_down;
}

MenuType	Menu::update(gdl::GameClock &gameClock_, gdl::Input &input, bool sound)
{
  static float	tempo = -1;
  MenuType	tmp;

  if (tempo == -1)
    tempo = gameClock_.getTotalGameTime();
  this->_camera.update();
  this->_cursor.update();
  tmp = this->move(tempo, gameClock_, input, sound);
  if (tmp == DEC_OPTION || tmp == INC_OPTION)
    return (tmp);
  else if (tempo + 0.2 < gameClock_.getTotalGameTime() && input.isKeyDown(gdl::Keys::Return))
    {
      if (sound)
	this->_snd_enter.PlaySound();
      tempo = gameClock_.getTotalGameTime();
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

MenuType	Menu::move(float &tempo, gdl::GameClock &gameClock_, gdl::Input &input, bool sound)
{
  Vector3f	tmp(this->_cursor.getTranslation());

  if (tempo + 0.2 < gameClock_.getTotalGameTime())
    {
      if (input.isKeyDown(gdl::Keys::Down))
	{
	  if (sound)
	    this->_snd_move.PlaySound();
	  this->_cursor.setTranslation(Vector3f(tmp.x, tmp.y - 65, tmp.z));
	  tempo = gameClock_.getTotalGameTime();
	  this->inc_choice();
	}
      else if (input.isKeyDown(gdl::Keys::Up))
	{
	  if (sound)
	    this->_snd_move.PlaySound();
	  this->_cursor.setTranslation(Vector3f(tmp.x, tmp.y + 65, tmp.z));
	  tempo = gameClock_.getTotalGameTime();
	  this->dec_choice();
	}
      else
	return this->change_option(input, tempo, gameClock_);
    }
  return NOTHING;
}

MenuType	Menu::getChoice() const
{
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

MenuType	Menu::change_option(gdl::Input &input, float &tempo, gdl::GameClock &gameClock_)
{
  if (input.isKeyDown(gdl::Keys::Left) && this->_list[this->_choice] == MAP_OPTION)
    {
      tempo = gameClock_.getTotalGameTime();
      return (DEC_OPTION);
    }
  else if (input.isKeyDown(gdl::Keys::Right) && this->_list[this->_choice] == MAP_OPTION)
    {
      tempo = gameClock_.getTotalGameTime();
      return (INC_OPTION);
    }
  return NOTHING;
}
