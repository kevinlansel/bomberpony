//
// Player.hpp for bomberman in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu May  9 11:20:52 2013 gery baudry
// Last update Tue May 14 11:19:34 2013 gery baudry
//

#ifndef		PLAYER_HPP__
# define	PLAYER_HPP__

//#define		SPEED		1

#include	"Input.hpp"
#include	"APlayer.hpp"

class		Player : public APlayer
{
public:
  Player(bool);
  virtual	~Player();

public:
  void		update(gdl::Input &);

private:
  void		move(int);
  void		move_player_one(gdl::Input &input);
  void		move_player_two(gdl::Input &input);

private:
  bool		_joueur;	// true = j1, false = j2
  int		_bomb;
};

#endif
