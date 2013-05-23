//
// Explosion.hpp for Explosion in /home/haz3/projet/bomberpony/testgdl
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Wed May 22 12:45:08 2013 Maxime Wojciak
// Last update Thu May 23 15:48:21 2013 Maxime Wojciak
//

#ifndef		_EXPLOSION__
#define		_EXPLOSION__

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

class Explosion {
  public:
    Explosion(const Vector3f &, unsigned int);
    ~Explosion();

  public:
    void	initialize(void);
    void	update(gdl::GameClock &);
    void	draw(void);
    void	unload(void);
  private:
    Vector3f			_coord;
    unsigned int		_Xplosize;
    std::list<gdl::Model>	_explosion;
    std::list<bool>		_tempo;
};

#endif		/* !_EXPLOSION__ */
