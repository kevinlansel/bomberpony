//
// Bombe.hpp for Bombe in /home/haz3/projet/bomberpony
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Mon May 13 10:55:02 2013 Maxime Wojciak
// Last update Mon May 13 22:47:17 2013 florian dewulf
//

#ifndef		_BOMBE__
# define	_BOMBE__

#include	<list>
#include	<iostream>
#include	<string>
#include	"GameClock.hpp"

class		Bombe {
public:
  Bombe();
  virtual ~Bombe();

public:
  /* getter & setter */

public:
  void	DropBombe(int, int, const gdl::GameClock &);

private:

};

#endif /* !_BOMBE__ */
