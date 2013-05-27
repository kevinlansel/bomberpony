//
// InputBox.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Fri May 24 23:21:07 2013 florian dewulf
// Last update Sun May 26 18:45:40 2013 florian dewulf
//

#include	"InputBox.hpp"

InputBox::InputBox(MenuType joueur) : Scene(Vector3f(0, 0, 500), Vector3f(0, 0, 0)), _player((joueur == ONE) ? 1 : 2), _strJ1(""), _strJ2(""), _state(true), _count(0), _last_time(0), _curs(0)
{
}

InputBox::~InputBox()
{
}

void		InputBox::initialize(const std::string &str, const Vector3f &position, const Vector3f &color_default)
{
  (void)(str);
  (void)(position);
  this->_colorJ1 = color_default;
  this->_colorJ2 = color_default;
  this->setColorRed();
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
      switch (this->_curs)
	{
	case 0:
	  this->_colorJ1.x++;
	  if (this->_colorJ1.x == 256)
	    this->_colorJ1.x = 0;
	  break;
	case 1:
	  this->_colorJ1.y++;
	  if (this->_colorJ1.y == 256)
	    this->_colorJ1.y = 0;
	  break;
	case 2:
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
      switch (this->_curs)
	{
	case 0:
	  this->_colorJ2.x++;
	  if (this->_colorJ2.x == 256)
	    this->_colorJ2.x = 0;
	  break;
	case 1:
	  this->_colorJ2.y++;
	  if (this->_colorJ2.y == 256)
	    this->_colorJ2.y = 0;
	  break;
	case 2:
	  this->_colorJ2.z++;
	  if (this->_colorJ2.z == 256)
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
      switch (this->_curs)
	{
	case 0:
	  this->_colorJ1.x--;
	  if (this->_colorJ1.x == -1)
	    this->_colorJ1.x = 255;
	  break;
	case 1:
	  this->_colorJ1.y--;
	  if (this->_colorJ1.y == -1)
	    this->_colorJ1.y = 255;
	  break;
	case 2:
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
      switch (this->_curs)
	{
	case 0:
	  this->_colorJ2.x--;
	  if (this->_colorJ2.x == -1)
	    this->_colorJ2.x = 255;
	  break;
	case 1:
	  this->_colorJ2.y--;
	  if (this->_colorJ2.y == -1)
	    this->_colorJ2.y = 255;
	  break;
	case 2:
	  this->_colorJ2.z--;
	  if (this->_colorJ2.z == -1)
	    this->_colorJ2.z = 255;
	  break;
	default:
	  break;
	}
    }
}

void		InputBox::mouv_vertical(gdl::Input &input)
{
  if (input.isKeyDown(gdl::Keys::Up)) {
    this->UpColor();
  }
  else if (input.isKeyDown(gdl::Keys::Down)) {
    this->DownColor();
  }
}

void		InputBox::mouv_lateral(gdl::Input &input)
{
  if (input.isKeyDown(gdl::Keys::Left)) {
    this->_curs--;
    if (this->_curs == -1)
      this->_curs = 2;
  }
  else if (input.isKeyDown(gdl::Keys::Right)) {
    this->_curs++;
    if (this->_curs == 3)
      this->_curs = 0;
  }
}

void		InputBox::mouvement(gdl::Input &input)
{
  if (this->_state == false) {
    this->mouv_lateral(input);
    this->mouv_vertical(input);
  }
}

MenuType	InputBox::update(gdl::GameClock &clock, gdl::Input &input, bool useless)
{
  gdl::Keys::Key	tabKey[] = {gdl::Keys::A, gdl::Keys::B, gdl::Keys::C, gdl::Keys::D, gdl::Keys::E, gdl::Keys::F, gdl::Keys::G, gdl::Keys::H, gdl::Keys::I, gdl::Keys::J, gdl::Keys::K, gdl::Keys::L, gdl::Keys::M, gdl::Keys::N, gdl::Keys::O, gdl::Keys::P, gdl::Keys::Q, gdl::Keys::R, gdl::Keys::S, gdl::Keys::T, gdl::Keys::U, gdl::Keys::V, gdl::Keys::W, gdl::Keys::X, gdl::Keys::Y, gdl::Keys::Z};
  std::string	tabChar = "abcdefghijklmnopqrstuvwxyz";
  bool		indice = true;

  (void)(useless);
  if (this->_last_time == 0)
    this->_last_time = clock.getTotalGameTime();
  if (this->_last_time + 0.07 < clock.getTotalGameTime())
    {
      for (unsigned int i = 0 ; i < 26 && indice && this->_state; ++i)
	if (input.isKeyDown(tabKey[i]))
	  {
	    indice = false;
	    this->addChar(tabChar[i]);
	  }

      if (input.isKeyDown(gdl::Keys::Return) && ((this->_count == 0 && this->_strJ1 != "") || (this->_count == 1 && this->_strJ2 != "")))
	{
	  this->_state = (this->_state) ? false  : true;
	  if (this->_state)
	    {
	      this->_count++;
	      this->_curs = 0;
	    }
	}
      else if (input.isKeyDown(gdl::Keys::Back) && this->_state == true)
	this->reduceStr();
      else
	this->mouvement(input);

      this->_last_time = clock.getTotalGameTime();
    }

  if (this->_player == 1)
    this->setTxt((this->_strJ1 + "\n" + Utils::IntToString(this->_colorJ1.x) + " " + Utils::IntToString(this->_colorJ1.y) + " " + Utils::IntToString(this->_colorJ1.z)), 100, 100);
  else
    this->setTxt((this->_strJ1 + "\n" + Utils::IntToString(this->_colorJ1.x) + " " + Utils::IntToString(this->_colorJ1.y) + " " + Utils::IntToString(this->_colorJ1.z) + "\n" + this->_strJ2 + "\n" + Utils::IntToString(this->_colorJ2.x) + " " + Utils::IntToString(this->_colorJ2.y) + " " + Utils::IntToString(this->_colorJ2.z)), 100, 100);
  if (this->_count == this->_player)
    return END_INPUT;
  return NOTHING;
}

void		InputBox::draw()
{
  gdl::Text	echantillon;

  echantillon.setText("Color !");
  echantillon.setPosition(400, 400);
  if (this->_count == 0)
    echantillon.setColor(gdl::Color(this->_colorJ1.x, this->_colorJ1.y, this->_colorJ1.z));
  else
    echantillon.setColor(gdl::Color(this->_colorJ2.x, this->_colorJ2.y, this->_colorJ2.z));
  this->_txt.draw();
  echantillon.draw();
}
