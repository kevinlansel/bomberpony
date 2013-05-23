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

#include	<list>

#include	"Player.hpp"
#include	"Obstacle.hpp"
#include	"Bombe.hpp"

class		Collision
{
public:
  Collision();
  virtual ~Collision();
  bool	checkCollisionWall();
  bool	checkCollisionBomb();
  bool	getCollision() const;

private:
  std::list<Bombe *>	*_bomb;
  std::list<Player *>	*_play;
  std::list<Obstacle *>	*_obs;
  bool			_collision;
};

#endif
