//
// Player.hpp for bomberman in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu May  9 11:20:52 2013 gery baudry
// Last update Mon May 13 14:18:45 2013 gery baudry
//

#ifndef		PLAYER_HPP__
# define	PLAYER_HPP__

//#define		SPEED		1

#include	"Input.hpp"

class		Player
{
public:
  Player(bool);
  virtual	~Player();

public:
  int		getWinx() const;
  int		getWiny() const;
  int		getBomb() const;
  void		setWinx(int);
  void		setWiny(int);
  void		setBomb(int);
  void		update(gdl::Input &);

private:
  void		move_player_one(gdl::Input &input);
  void		move_player_two(gdl::Input &input);

private:
  int		_winx;
  int		_winy;

private:
  bool		_joueur;	// true = j1, false = j2
  int		_bomb;
};

#endif
