#ifndef		__OBSTACLE_HPP__
# define	__OBSTACLE_HPP__

class		Obstacle
{
public:
  Obstacle();
  virtual ~Obstacle();

  enum		typeObs
    {
      WALL,
      BREAKABLE_WALL
    };

  typeObs	getType() const;
  int		getX() const;
  int		getY() const;
  void		setX(int);
  void		setY(int);

private:
  typeObs	_type;
  int		_x;
  int		_y;
};

#endif
