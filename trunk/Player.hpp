//
// Player.hpp for bomberman in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu May  9 11:20:52 2013 gery baudry
// Last update Sun May 26 15:25:36 2013 florian dewulf
//

#ifndef		PLAYER_HPP__
# define	PLAYER_HPP__

//#define		SPEED		1

#include	"Input.hpp"
#include	"APlayer.hpp"
#include	"GameClock.hpp"

class		Player : public APlayer
{
public:
  Player(bool);
  virtual	~Player();

public:
  void		update(gdl::Input &, gdl::GameClock &, const std::list<Obstacle *> &, const std::list<Bombe *> &);

private:
  void		move_player_one(gdl::Input &input);
  void		move_player_two(gdl::Input &input);

};

#endif
