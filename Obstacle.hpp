#ifndef		__OBSTACLE_HPP__
# define	__OBSTACLE_HPP__

#include	"AObject.hpp"

class		Obstacle : public AObject
{
public:
  Obstacle();
  virtual ~Obstacle();

  enum		typeObs
    {
      WALL,
      BREAKABLE_WALL
    };

  void		initialize();
  void		update();
  void		draw();
  typeObs	getType() const;
  int		getX() const;
  int		getY() const;
  int		getZ() const;
  void		setX(int);
  void		setY(int);
  void		setZ(int);

private:
  typeObs	_type;
  Vector3f	_v;
};

#endif
