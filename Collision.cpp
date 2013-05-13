//
// Collision.cpp for bomberman in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon May 13 10:49:32 2013 gery baudry
// Last update Mon May 13 13:51:34 2013 gery baudry
//

#include	"Collision.hpp"

Collision::Collision(): collision(false)
{

}

Collision::~Collision()
{

}

bool		Collision::checkCollisionWall()
{
  this->collision = false;
  // si la position du player == a la position d'un obstacle
  /*if (this->p1->getWinx() == obs->getX())
    if (this->p1->getWiny() == obs->getY())
    this->collision = true;*/
  return (this->collision);
}

bool		Collision::checkCollisionPlayer()
{
  // si la position du player == a la position d'un autre player
  this->collision = false;
  /*if (this->p1->getWinx() == this->p2->getWinx())
    if (this->p1->getWiny() == this->p2->getWiny())
      this->collision = true;*/
  return (this->collision);
}

bool		Collision::getCollision() const
{
  return (this->collision);
}
