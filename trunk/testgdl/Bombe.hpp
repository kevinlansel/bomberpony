//
// Bombe.hpp for Bombe in /home/haz3/projet/bomberpony
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Mon May 13 10:55:02 2013 Maxime Wojciak
// Last update Wed May 22 12:30:09 2013 Maxime Wojciak
//

#ifndef		_BOMBE__
# define	_BOMBE__

#include	<GL/glu.h>
#include	<GL/glut.h>

#include	<list>
#include	<iostream>
#include	<string>
#include	<cstring>
#include	<unistd.h>
#include	"Vector3f.hpp"
#include	"GameClock.hpp"
#include	"Model.hpp"
#include	"Input.hpp"

class		Bombe {
public:
  Bombe();
  virtual	~Bombe();

public:
  void		initialize();
  void		update(gdl::GameClock &, gdl::Input &);
  void		draw();
  void		unload();
  void		setCoord(Vector3f);
  Vector3f	getCoord();

private:
  Vector3f	_translation;
  gdl::Model	_BombeModel;
  gdl::Model	_ExplosionModel;
};

#endif /* !_BOMBE__ */
