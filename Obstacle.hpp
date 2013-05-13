#ifndef		__OBSTACLE_HPP__
# define	__OBSTACLE_HPP__

class		Obstacle
{
public:
  typedef enum		typeObs
    {
      WALL		1,
      BREAKABLE_WALL	2
    };
  Obstacle();
  virtual ~Obstacle();
  typeObs	getType() const;
  int		getX() const;
  int		getY() const;
  void		setX(int);
  void		setY(int);

private:
  typeObs	_type;
  int		_x;
  int		_y;
}

#endif
