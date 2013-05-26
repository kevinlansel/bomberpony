//
// Explosion.hpp for Explosion in /home/haz3/projet/bomberpony/testgdl
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Wed May 22 12:45:08 2013 Maxime Wojciak
// Last update Sun May 26 02:21:54 2013 florian dewulf
//

#ifndef		_EXPLOSION__
#define		_EXPLOSION__

#include	<GL/glu.h>
#include	<GL/glut.h>

#include	<list>
#include	<string>
#include	"Forme.hpp"
#include	"Vector3f.hpp"
#include	"GameClock.hpp"
#include	"Model.hpp"

class Explosion {
public:
  Explosion(const Vector3f &, unsigned int);
  ~Explosion();

public:
  void	initialize(void);
  bool	update(gdl::GameClock &);
  void	draw(void);

private:
  float				_time;
  Vector3f			_BombPos;
  unsigned int			_Xplosize;
  std::list<Rectangle *>	_explosion;
  //  std::list<gdl::Model>	_explosion;
};

#endif		/* !_EXPLOSION__ */
