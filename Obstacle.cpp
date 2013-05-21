#include	"Obstacle.hpp"

Obstacle::Obstacle()
{
  // generation du positionnement en x et y ainsi que le type d'obstacle
}

Obstacle::~Obstacle()
{
}

void		Obstacle::initialize()
{

}

void		Obstacle::update()
{

}

void		Obstacle::draw()
{

}

Obstacle::typeObs	Obstacle::getType() const
{
  return (this->_type);
}

int		Obstacle::getX() const
{
  return (this->_v.x);
}

int		Obstacle::getY() const
{
  return (this->_v.y);
}

int		Obstacle::getZ() const
{
  return (this->_v.z);
}

void		Obstacle::setX(int x)
{
  this->_v.x = x;
}

void		Obstacle::setY(int y)
{
  this->_v.y = y;
}

void		Obstacle::setZ(int z)
{
  this->_v.z = z;
}
