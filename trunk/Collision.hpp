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
