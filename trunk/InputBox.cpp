//
// InputBox.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Fri May 24 23:21:07 2013 florian dewulf
// Last update Sat May 25 01:40:20 2013 florian dewulf
//

#include	"InputBox.hpp"

InputBox::InputBox(MenuType joueur) : _player((joueur == ONE) ? 1 : 2), _strJ1(""), _strJ2(""), _state(true), _count(0), _last_time(0), _curs(0)
{
  this->_model = gdl::Model::load("./ressource/marvin.fbx");
}

InputBox::~InputBox()
{
}

void		InputBox::initialize(const std::string &str, const Vector3f &position, const Vector3f &color_default)
{
  this->_colorJ1 = color_default;
  this->_colorJ2 = color_default;
}

void		InputBox::addChar(char c)
{
  if (this->_count == 0)
    {
      if (this->_strJ1.size() == 6)
	this->_strJ1[5] = c;
      else
	this->_strJ1 += c;
    }
  else
    {
      if (this->_strJ2.size() == 6)
	this->_strJ2[5] = c;
      else
	this->_strJ2 += c;
    }
}

void		InputBox::reduceStr()
{
  if (this->_count == 0 && this->_strJ1.size() > 0)
    this->_strJ1 = this->_strJ1.substr(0, this->_strJ1.size() - 1);
  else if (this->_count == 1 && this->_strJ2.size() > 0)
    this->_strJ2 = this->_strJ2.substr(0, this->_strJ2.size() - 1);
}

void		InputBox::UpColor()
{
  if (this->_count == 0 && this->_state == false)
    {
      switch (1)
	{
	case (int)(this->_curs == 0):
	  this->_colorJ1.x++;
	  if (this->_colorJ1.x == 256)
	    this->_colorJ1.x = 0;
	  break;
	case (int)(this->_curs == 1):
	  this->_colorJ1.y++;
	  if (this->_colorJ1.y == 256)
	    this->_colorJ1.y = 0;
	  break;
	case (int)(this->_curs == 2):
	  this->_colorJ1.z++;
	  if (this->_colorJ1.z == 256)
	    this->_colorJ1.z = 0;
	  break;
	default:
	  break;
	}
    }
  else if (this->_count == 1 && this->_state == false)
    {
      switch (1)
	{
	case (int)(this->_curs == 0):
	  this->_colorJ2.x++;
	  if (this->_colorJ1.x == 256)
	    this->_colorJ2.x = 0;
	  break;
	case (int)(this->_curs == 1):
	  this->_colorJ2.y++;
	  if (this->_colorJ1.y == 256)
	    this->_colorJ2.y = 0;
	  break;
	case (int)(this->_curs == 2):
	  this->_colorJ2.z++;
	  if (this->_colorJ1.z == 256)
	    this->_colorJ2.z = 0;
	  break;
	default:
	  break;
	}
    }
}

void		InputBox::DownColor()
{
  if (this->_count == 0 && this->_state == false)
    {
      switch (1)
	{
	case (int)(this->_curs == 0):
	  this->_colorJ1.x--;
	  if (this->_colorJ1.x == -1)
	    this->_colorJ1.x = 255;
	  break;
	case (int)(this->_curs == 1):
	  this->_colorJ1.y--;
	  if (this->_colorJ1.y == -1)
	    this->_colorJ1.y = 255;
	  break;
	case (int)(this->_curs == 2):
	  this->_colorJ1.z--;
	  if (this->_colorJ1.z == -1)
	    this->_colorJ1.z = 255;
	  break;
	default:
	  break;
	}
    }
  else if (this->_count == 1 && this->_state == false)
    {
      switch (1)
	{
	case (int)(this->_curs == 0):
	  this->_colorJ2.x--;
	  if (this->_colorJ1.x == -1)
	    this->_colorJ2.x = 255;
	  break;
	case (int)(this->_curs == 1):
	  this->_colorJ2.y--;
	  if (this->_colorJ1.y == -1)
	    this->_colorJ2.y = 255;
	  break;
	case (int)(this->_curs == 2):
	  this->_colorJ2.z--;
	  if (this->_colorJ1.z == -1)
	    this->_colorJ2.z = 255;
	  break;
	default:
	  break;
	}
    }
}

MenuType	InputBox::update(gdl::GameClock &clock, gdl::Input &input, bool useless)
{
  (void)(useless);
  if (this->_last_time + 0.2 < clock.getTotalGameTime())
    {
      switch (1)
	{
	case (int)(input.isKeyDown(gdl::Keys::A) && this->_state == true):
	  this->addChar('a');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::B) && this->_state == true):
	  this->addChar('b');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::C) && this->_state == true):
	  this->addChar('c');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::D) && this->_state == true):
	  this->addChar('d');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::E) && this->_state == true):
	  this->addChar('e');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::F) && this->_state == true):
	  this->addChar('f');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::G) && this->_state == true):
	  this->addChar('g');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::H) && this->_state == true):
	  this->addChar('h');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::I) && this->_state == true):
	  this->addChar('i');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::J) && this->_state == true):
	  this->addChar('j');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::K) && this->_state == true):
	  this->addChar('k');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::L) && this->_state == true):
	  this->addChar('l');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::M) && this->_state == true):
	  this->addChar('m');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::N) && this->_state == true):
	  this->addChar('n');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::O) && this->_state == true):
	  this->addChar('o');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::P) && this->_state == true):
	  this->addChar('p');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::Q) && this->_state == true):
	  this->addChar('q');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::R) && this->_state == true):
	  this->addChar('r');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::S) && this->_state == true):
	  this->addChar('s');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::T) && this->_state == true):
	  this->addChar('t');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::U) && this->_state == true):
	  this->addChar('u');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::V) && this->_state == true):
	  this->addChar('v');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::W) && this->_state == true):
	  this->addChar('w');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::X) && this->_state == true):
	  this->addChar('x');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::Y) && this->_state == true):
	  this->addChar('y');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::Z) && this->_state == true):
	  this->addChar('z');
	  break;
	case (int)(input.isKeyDown(gdl::Keys::Return)):
	  this->_state = (this->_state) ? false : true;
	  if (this->_state)
	    {
	      this->_count++;
	      this->_curs = 0;
	    }
	  break;
	case (int)(input.isKeyDown(gdl::Keys::Back) && this->_state == true):
	  this->reduceStr();
	  break;
	case (int)(input.isKeyDown(gdl::Keys::Left) && this->_state == false):
	  this->_curs--;
	  if (this->curs == -1)
	    this->_curs = 2;
	  break;
	case (int)(input.isKeyDown(gdl::Keys::Right)):
	  this->_curs++;
	  if (this->curs == 3)
	    this->_curs = 0;
	  break;
	case (int)(input.isKeyDown(gdl::Keys::Up)):
	  this->UpColor();
	  break;
	case (int)(input.isKeyDown(gdl::Keys::Down)):
	  this->DownColor();
	  break;
	default:
	  break;
	}
      this->_last_time = clock.getTotalGameTime();
    }
  this->_model.play("Take 001");
  this->_model.update();
  if (this->_count == 2)
    return END_INPUT;
  return NOTHING;
}

void		InputBox::draw()
{
  if (this->_count == 0)
    this->_model.set_default_model_color(gdl::Color(this->_colorJ1.x, this->_colorJ1.y, this->_colorJ1.z));
  else
    this->_model.set_default_model_color(gdl::Color(this->_colorJ2.x, this->_colorJ2.y, this->_colorJ2.z));
  this->_model.draw();
}
