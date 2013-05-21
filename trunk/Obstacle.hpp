#ifndef		__OBSTACLE_HPP__
# define	__OBSTACLE_HPP__

#include	"AObject.hpp"

class		Obstacle : public AObject
{
public:
  enum		typeObs
    {
      UNBREAKABLE_WALL,
      BREAKABLE_WALL
    };
  
  Obstacle(const Vector3f &, typeObs);
  virtual ~Obstacle();
  
  void		initialize();
  void		update();
  void		draw();
  typeObs	getType() const;
  void		setType(typeObs);
  Vector3f	getPosition() const;
  void		setPosition(const Vector3f &);

private:
  typeObs	_type;
  Vector3f	_v;
};

#endif
