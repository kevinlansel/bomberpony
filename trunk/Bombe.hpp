//
// Bombe.hpp for Bombe in /home/haz3/projet/bomberpony
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Mon May 13 10:55:02 2013 Maxime Wojciak
// Last update Tue May 21 11:11:53 2013 Maxime Wojciak
//

#ifndef		_BOMBE__
# define	_BOMBE__

#include	<list>
#include	<iostream>
#include	<string>
#include	"Menu.hpp"
#include	"Vector3f.hpp"
#include	"GameClock.hpp"

class		Bombe {
public:
  Bombe();
  virtual	~Bombe();

public:
  void		setCoord(Vector3f);
  Vector3f	getCoord();

public:
  void		Draw();
  void		DropBombe(Vector3f, const gdl::GameClock &);

private:
  Vector3f	_coord;
};

#endif /* !_BOMBE__ */
