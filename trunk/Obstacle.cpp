#include	"Obstacle.hpp"

Obstacle::Obstacle(const Vector3f &v, Obstacle::typeObs obs):
  _v(v), _type(obs)
{
  
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

void	Obstacle::setType(Obstacle::typeObs obs)
{
  this->_type = obs;
}

Vector3f	Obstacle::getPosition() const
{
  return (this->_v);
}

void		Obstacle::setPosition(const Vector3f &v)
{
  this->_v = v;
}
