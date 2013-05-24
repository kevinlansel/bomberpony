//
// Bot.hpp for Bomberman in /home/seth/C++/bomberpony
// 
// Made by kevin lansel
// Login   <lansel_k@epitech.net>
// 
// Started on  Mon May 13 17:05:47 2013 kevin lansel
// Last update Fri May 24 15:32:20 2013 kevin lansel
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

  void		update(gld::GameClock &, gdl::Input &, const std::list<Obstacle> &, const std::list<Bombe *> &bombe);

private:
  void		easy(const std::list<Obstacle *> &, const std::list<Bombe *> &);
  void		medium(const std::list<Obstacle *> &, const std::list<Bombe *> &);
  void		hard(const std::list<Obstacle *> &, const std::list<Bombe *> &);

  void		rdoff(const std::list<Bombe *> &);
  void		rddef(const std::list<Obstacle *> &, const std::list<Bombe *> &);
  void		offensif(const std::list<Bombe> &);
  void		defensif(const std::list<Obstacle *> &, const std::list<Bombe *> &, const std::vector<std::string> &);

  bool		secure(const std::vector<std::string>);
  bool		trymove(const std::list<Bombe *> &, const std::list<Obstacle *> &, unsigned int, unsigned int);
  unsigned int	giveUp(unsigned int, unsigned int, std::vector<std::string>);
  unsigned int	giveDown(unsigned int, unsigned int, std::vector<std::string>);
  unsigned int	giveRight(unsigned int, unsigned int, std::vector<std::string>);
  unsigned int	giveLeft(unsigned int, unsigned int, std::vector<std::string>);

  eDir                    giveMove(const std::list<Obstacle> &, std::vector<std::string> &);
  void                    putExplosion(std::vector<std::string> &, const int &, const int &, const unsigned int &);
  std::vector<std::string>        BombMapGenerator(const std::list<Bombe *> &);
  void                            PondCase(const std::vector<std::string> &, int, int);
  bool                            checkCase(const std::vector<std::string> &, const int, const int);
  bool                            checkLine(const std::vector<std::string> &, int *, int *);
  void                            PondLine(bool, bool, std::vector<std::string> &);
  std::vector<std::string>        PondDir(const std::vector<std::string> &);
  void                            Bot::MoveBot(eDir);

private:
  unsigned int	_x;
  unsigned int	_y;
  unsigned int	_size;
  Vector3f	_posActu;
  Vector3f	_destination;
  eMode		_mode;
};

#endif	/* BOT_HPP_ */
