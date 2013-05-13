//
// Collision.hpp for bomberman in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon May 13 10:49:44 2013 gery baudry
// Last update Mon May 13 10:49:59 2013 gery baudry
//

#ifndef		__COLLISION_HPP__
# define	__COLLISION_HPP__

#include	"Player.hpp"

class		Collision
{
public:
  Collision();
  ~Collision();
  bool	checkCollisionWall();
  bool	checkCollisionPlayer();

private:
  Player	*p1;
  Player	*p2;
  Obstacle	*obs;
  bool		collision;
}

#endif
