//
// Player.hpp for bomberman in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu May  9 11:20:52 2013 gery baudry
// Last update Tue May 14 11:24:58 2013 gery baudry
//

#ifndef		APLAYER_HPP__
# define	APLAYER_HPP__

#include	<iostream>
#include	<list>
#include	"Input.hpp"
#include	"Obstacle.hpp"
#include	"Vector3f.hpp"

class		APlayer
{
public:
  APlayer(int joueur, const std::string &name);
  virtual		~APlayer();

public:
  Vector3f		getPos() const;
  int			getJoueur() const;
  int			getBomb() const;
  std::string		getName() const;
  bool			getAlive() const;

public:
  void			setPos(Vector3f);
  void			setJoueur(int);
  void			setBomb(int);
  void			setName(std::string &);
  void			setAlive(bool);

public:
  virtual void		update(gdl::Input &) = 0;
  virtual void		initialize(const std::list<Obstacle> &) = 0;

private:
  void			move_player_one(gdl::Input &input);
  void			move_player_two(gdl::Input &input);

protected:
  Vector3f		_pos;

private:
  int			_joueur;	// 1 = J1 / 2 = J2 / -1 = bot
  int			_bomb;
  std::string		_name;
  bool			_alive;
};

#endif
