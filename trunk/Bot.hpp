//
// Bot.hpp for Bomberman in /home/seth/C++/bomberpony
// 
// Made by kevin lansel
// Login   <lansel_k@epitech.net>
// 
// Started on  Mon May 13 17:05:47 2013 kevin lansel
// Last update Mon May 20 13:37:46 2013 kevin lansel
//

#ifndef		BOT_HPP_
# define	BOT_HPP_

#include	<string>
#include	"APlayer.hpp"
#include	"Bomberman.h"

class Bot : public APlayer
{
public:
  Bot(unsigned int, unsigned int, unsigned int, eMode);
  ~Bot();

  void		setMode(eMode);
  void		setX(unsigned int);
  void		setY(unsigned int);
  eMode		getMode(void) const;
  unsigned int	getX(void) const;
  unsigned int	getY(void) const;

  void		update(gld::GameClock &, gdl::Input &, const std::list<Obstacle> &);

private:
  unsigned int	_x;
  unsigned int	_y;
  unsigned int	_size;
  eMode		_mode;

  void		easy();
  void		medium();
  void		hard();
};

#endif	/* BOT_HPP */
