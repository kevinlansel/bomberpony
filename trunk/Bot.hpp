//
// Bot.hpp for Bomberman in /home/seth/C++/bomberpony
// 
// Made by kevin lansel
// Login   <lansel_k@epitech.net>
// 
// Started on  Mon May 13 17:05:47 2013 kevin lansel
// Last update Tue May 14 18:46:57 2013 kevin lansel
//

#ifndef		BOT_HPP_
# define	BOT_HPP_

#include	<string>
#include	"APlayer.hpp"
#include	"Bomberman.h"

class Bot : public APlayer
{
public:
  Bot(eMode);
  ~Bot();

  void		setMode(eMode);
  eMode		getMode(void);

  void		initialize(const std::list<Obstacle> &);
  void		update(gdl::Input &);

private:
  eMode		_mode;
};

#endif	/* BOT_HPP */
