//
// Bot.hpp for Bomberman in /home/seth/C++/bomberpony
// 
// Made by kevin lansel
// Login   <lansel_k@epitech.net>
// 
// Started on  Mon May 13 17:05:47 2013 kevin lansel
// Last update Wed May 22 14:57:37 2013 florian dewulf
//

#ifndef		BOT_HPP_
# define	BOT_HPP_

#include	<string>
#include	"APlayer.hpp"
#include	"Bomberman.h"

enum		eDir
  {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    DEFAULT
  };

class Bot : public APlayer
{
public:
  Bot(unsigned int, unsigned int, unsigned int, eMode);
  virtual ~Bot();

  void		setMode(eMode);
  void		setX(unsigned int);
  void		setY(unsigned int);
  void		setSize(unsigned int);
  eMode		getMode(void) const;
  unsigned int	getX(void) const;
  unsigned int	getY(void) const;
  unsigned int	getSize(void) const;
  Vector3f	getPos() const;
  Vector3f	getDest() const;

  void		update(gld::GameClock &, gdl::Input &, const std::list<Obstacle> &);

private:
  void		easy();
  void		medium();
  void		hard();

  void		rdoff(const std::list<Bombe> &);
  void		rddef();
  void		offensif(const std::list<Bombe> &bombe);
  void		defensif(const std::list<Bombe> &bombe);

  bool		secure();
  bool		trymove(const std::list<Bombe> &, const std::list<Obstacle> &, unsigned int, unsigned int);

private:
  unsigned int	_x;
  unsigned int	_y;
  unsigned int	_size;
  Vector3f	_posActu;
  Vector3f	_destination;
  eMode		_mode;
};

#endif	/* BOT_HPP_ */
