//
// Explosion.hpp for Explosion in /home/haz3/projet/bomberpony/testgdl
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Wed May 22 12:45:08 2013 Maxime Wojciak
// Last update Wed May 22 12:48:12 2013 Maxime Wojciak
//

#ifndef		_EXPLOSION__
#define		_EXPLOSION__

class Explosion {
  public:
    Explosion();
    ~Explosion();

  public:

    /*getter & setter*/

  private:
    std::list<Explosion>	_explosion;
};

#endif		/* !_EXPLOSION__ */
