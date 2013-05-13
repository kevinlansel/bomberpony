#include	"Obstacle.hpp"

Obstacle::Obstacle()
{
  // generation du positionnement en x et y ainsi que le type d'obstacle
}

Obstacle::~Obstacle()
{
}

Obstacle::typeObs		Obstacle::getType() const
{
  return (this->_type);
}

int		Obstacle::getX() const
{
  return (this->_x);
}

int		Obstacle::getY() const
{
  return (this->_y);
}

void		Obstacle::setX(int x)
{
  this->_x = x;
}

void		Obstacle::setY(int y)
{
  this->_y = y;
}
