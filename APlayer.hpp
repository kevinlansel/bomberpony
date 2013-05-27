//
// Player.hpp for bomberman in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu May  9 11:20:52 2013 gery baudry
// Last update Sun May 26 15:43:34 2013 florian dewulf
//

#ifndef		APLAYER_HPP__
# define	APLAYER_HPP__

#include	<iostream>
#include	<list>
#include	"Model.hpp"
#include	"Input.hpp"
#include	"Obstacle.hpp"
#include	"Vector3f.hpp"
#include	"Bombe.hpp"
#include	"Obstacle.hpp"

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
  Vector3f		getTranslation() const;

public:
  void			setPos(Vector3f);
  void			setJoueur(int);
  void			setBomb(int);
  void			setName(std::string &);
  void			setAlive(bool);
  void			setTranslation(Vector3f);

public:
  virtual void		update(gdl::Input &, gdl::GameClock &, const std::list<Obstacle *> &, const std::list<Bombe *> &) = 0;
  virtual void		initialize() = 0;
  virtual void		draw() = 0;

protected:
  Vector3f		_pos;
  int			_joueur;	// 1 = J1 / 2 = J2 / -1 = bot
  int			_bomb;
  std::string		_name;
  bool			_alive;
  gdl::Model		_model;
};

#endif
