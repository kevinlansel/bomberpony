#include	"Obstacle.hpp"

Obstacle::Obstacle(const Vector3f &v, Obstacle::typeObs obs):
  _v(v), _type(obs)
{
  
}

Obstacle::~Obstacle()
{
  delete _cube;
}

void		Obstacle::initialize()
{
  this->_cube = new Cube(Vector3f(this->_v.x, 300, this->_v.z + 300), Vector3f(this->_v.x + 300, 0, this->_v.z), "./toto.tga");
}

void		Obstacle::update()
{

}

void		Obstacle::draw()
{
  this->_cube->draw();
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
