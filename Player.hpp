//
// Player.hpp for bomberman in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu May  9 11:20:52 2013 gery baudry
// Last update Fri May 10 15:29:33 2013 gery baudry
//

#ifndef		PLAYER_HPP__
# define	PLAYER_HPP__

//#define		SPEED		1

class		Player
{
public:
  Player();
  virtual	~Player();

public:
  int		getWinx() const;
  int		getWiny() const;
  int		getBomb() const;
  void		setWinx(int);
  void		setWiny(int);
  void		setBomb(int);

public:
  void		move_player_one(gdl::Input &input);
  void		move_player_two(gdl::Input &input);

private:
  int		_winx;
  int		_winy;

private:
  int		_bomb;
};

#endif
