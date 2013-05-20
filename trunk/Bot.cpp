//
// Bot.cpp for Bomberman in /home/seth/C++/bomberpony
// 
// Made by kevin lansel
// Login   <lansel_k@epitech.net>
// 
// Started on  Mon May 13 17:07:06 2013 kevin lansel
// Last update Mon May 20 16:58:43 2013 kevin lansel
//


#include	<stdlib.h>
#include	<time.h>
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
  srand(time(NULL));
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

void		Bot::setSize(unisgned int size)
{
  this->_size = size;
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

unsigned int	Bot::getSize() const
{
  return (this->_size);
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
  unsigned int		rd;

  rd = rand() % 2;
  if (rd == 1)
    rdoff();
  else
    rddef();
}

void		Bot::medium()
{
  if (secure())
    rdoff();
  else
    defensif();
}

void		Bot::hard()
{
  if (secure())
    offensif();
  else
    deffensif();
}

void		Bot::rdoff(const std::list<Bombe> &bombe)
{
  unsigned int		rd;
  Bombe			bim;

  rd = rand() % 7;
  if (rd == 0)
    {
      bim.setX(this->_x);
      bim.setY(this->_y);
      bombe.push_back();
    }
}

void		Bot::rddef()
{
  unsigned int		rd;

  rd = rand() % 4;
  switch (rd)
    {
    case 0: /* left */
      if (trymove(obs, this->_x - 1, this->_y))
	this->_x -= 1;
      break;
    case 1: /* right */
      if (trymove(obs, this->_x + 1, this->_y))
	this->_x += 1;
      break;
    case 2: /* up */
      if (trymove(obs, this->_x, this->_y + 1))
	this->_y += 1;
      break;
    case 3: /* down */
      if (trymove(obs, this->_x, this->_y - 1))
	this->_y -= 1;
      break;
    default:
      break;
    }
}

void		Bot::offensif(const std::list<Bombe> &bombe)
{

}

void		Bot::defensif(const std::list<Bombe> &bombe)
{

}

bool		Bot::secure(const std::list<Bombe> &bombe)
{
  for (std::list<Bombe>::iterator it = obs.begin() ; it != obs.end() ; ++it)
    {
      if (x == it.getX() && y == it.getY())
	return (false);
    }
  return (true);
}

bool		Bot::trymove(const std::list<Bombe> &bombe, const std::list<Obstacle> &obs, unsigned int x, unsigned int y)
{
  if (x == 0 || x == this->_size || y == 0 || y == this->_size)
    return (false);
  for (std::list<Obstacle>::iterator it = obs.begin() ; it != obs.end() ; ++it)
    {
      if (x == it.getX() && y == it.getY())
	return (false);
    }
  for (std::list<Bombe>::iterator it = bombe.begin() ; it != bombe.end() ; ++it)
    {
      if (x == it.getX() && y == it.getY())
	return (false);
    }
  return (true);
}
