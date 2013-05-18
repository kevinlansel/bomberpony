//
// Game.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Fri May 17 17:03:33 2013 florian dewulf
// Last update Sat May 18 12:20:27 2013 florian dewulf
//

#ifndef		GAME_HPP__
# define	GAME_HPP__

#include	<string>
#include	<list>
#include	<vector>

#include	"APlayer.hpp"
#include	"Obstacle.hpp"
#include	"Scene.hpp"
#include	"Vector3f.hpp"
#include	"Input.hpp"
#include	"GameClock.hpp"

class		Game : public Scene
{
public:
  Game(bool, bool);
  Game(bool, const std::list<std::string> &);
  virtual	~Game();

public:
  virtual void		initialize(const std::string &, const Vector3f &, const Vector3f &);
  virtual MenuType	update(gdl::GameClock &, gdl::Input &);
  virtual void		draw();

private:
  void			newPlayer(unsigned int, unsigned int, unsigned int);

private:
  bool				_error;
  bool				_nb_j;
  bool				_sound;
  bool				_map_choice;
  std::list<APlayer *>		_players;
  std::list<Obstacle *>		_obs;
  std::list<Bonus *>		_bonus;
};

#endif
