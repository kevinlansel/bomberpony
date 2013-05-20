//
// Bot.cpp for Bomberman in /home/seth/C++/bomberpony
// 
// Made by kevin lansel
// Login   <lansel_k@epitech.net>
// 
// Started on  Mon May 13 17:07:06 2013 kevin lansel
// Last update Mon May 20 13:38:00 2013 kevin lansel
//

#include	<sstream>
#include	"Bot.hpp"

static std::string	giveName()
{
  static int		id = 1;
  std::stringstream	ss;

  ss.str("Bot-");
  ss << id;
  id += 1;
  return (ss.str());
}

Bot::Bot(unsigned int x, unsigned int y, unsigned int size, eMode m) : Player(-1, giveName()), _x(x), _y(y), _size(size), _mode(m)
{

}

Bot::~Bot()
{

}

void		Bot::setMode(eMode mode)
{
  this->_mode = mode;
}

void		Bot::setX(unsigned int x)
{
  this->_x = x;
}

void		Bot::setY(unsigned int y)
{
  this->_y = y;
}

eMode		Bot::getMode() const
{
  return (this->_mode);
}

unsigned int	Bot::getX() const
{
  return (this->_x);
}

unsigned int	Bot::getY() const
{
  return (this->_y);
}

void		Bot::update(gld::GameClock &clock, gdl::Input &in, const std::list<Obstacle> &obs)
{
  (void)in;
  if (this->_mode == EASY)
    easy();
  else if (this->_mode == MEDIUM)
    medium();
  else
    hard();
}

void		Bot::easy()
{

}

void		Bot::medium()
{

}

void		Bot::hard()
{

}
