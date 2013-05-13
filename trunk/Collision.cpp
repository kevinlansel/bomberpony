#include	"Collision.hpp"

Collision::Collision(): 
  collision(false)
{
 
}

Collision::~Collision()
{

}

bool		Collision::checkCollisionWall()
{
  // si la position du player == a la position d'un obstacle
  if (this->p1->getWinX() == obs->getX())
    if (this->p1->getWinY() == obs->getY())
      this->collision = 1;
}

bool		Collision::checkCollisionPlayer()
{
  // si la position du player == a la position d'un autre player
  if (this->p1->getWinX() == this->p2->getX())
    if (this->p1->getWinY() == this->p2->getY())
      this->collision = 1;
}
