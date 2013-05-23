//
// Collision.cpp for bomberman in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon May 13 10:49:32 2013 gery baudry
// Last update Thu May 23 16:38:41 2013 gery baudry
//

#include	"Collision.hpp"

Collision::Collision(): _collision(false)
{
  // avec les listes
  // prendre certainement un joueur et une bombe en parametre
}

Collision::~Collision()
{

}

bool		Collision::checkCollisionWall()
{
  this->_collision = false;

  for (std::list<Player *>::iterator it1 = this->_play->begin(); it1 != this->_play->end(); ++it1)
    {
      Vector3f	PlayPos = (*it1)->getPos();
      for (std::list<Obstacle *>::iterator it2 = this->_obs->begin(); it2 != this->_obs->end(); ++it2)
	{
	  Vector3f	ObsPos = (*it2)->getPosition();
	  if (PlayPos.x == ObsPos.x)
	    {
	      if (PlayPos.z == ObsPos.z)
		{
		  this->_collision = true;
		  return (this->_collision);
		}
	    }
	}
    }
  return (this->_collision);
}

bool		Collision::checkCollisionBomb()
{
  this->_collision = false;

  for (std::list<Player *>::iterator it1 = this->_play->begin(); it1 != this->_play->end(); ++it1)
    {
      Vector3f	PlayPos = (*it1)->getPos();
      for (std::list<Bombe *>::iterator it2 = this->_bomb->begin(); it2 != this->_bomb->end(); ++it2)
	{
	  Vector3f	BombPos = (*it2)->getCoord();
	  if (PlayPos.x == BombPos.x)
	    {
	      if (PlayPos.z == BombPos.z)
		{
		  this->_collision = true;
		  return (this->_collision);
		}
	    }
	}
    }
  return (this->_collision);
}

bool		Collision::getCollision() const
{
  return (this->_collision);
}
