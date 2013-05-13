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
  
private:
  typeObs	_type;
}

#endif
