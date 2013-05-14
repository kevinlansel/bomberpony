//
// Bot.cpp for Bomberman in /home/seth/C++/bomberpony
// 
// Made by kevin lansel
// Login   <lansel_k@epitech.net>
// 
// Started on  Mon May 13 17:07:06 2013 kevin lansel
// Last update Tue May 14 11:19:06 2013 kevin lansel
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

Bot::Bot(eMode m) : Player(-1, giveName())
{
}

Bot::~Bot()
{

}

void		Bot::initialize(const std::list<Obstacle> &)
{

}

void		Bot::update(gdl::Input &in)
{
  (void)in;
}
