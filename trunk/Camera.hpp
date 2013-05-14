//
// Camera.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 19:09:38 2013 florian dewulf
// Last update Tue May 14 10:27:38 2013 florian dewulf
//

#ifndef		CAMERA_HPP__
# define	CAMERA_HPP__

#include	<GL/glu.h>
#include	<GL/glut.h>

#include	<cmath>

#include	"GameClock.hpp"
#include	"Input.hpp"
#include	"Vector3f.hpp"

class		Camera
{
public:
  Camera(void);
  void		initialize(int, int, const Vector3f &, const Vector3f &, float);
  void		update();
  void		draw();
  void		move(const Vector3f &, const Vector3f &, float, float);

public:
  Vector3f	getPosition() const;
  Vector3f	getTarget() const;
  float		getAngle() const;
  float		getRotation() const;

private:
  Vector3f	calc_rot() const;

private:
  float		_angle;
  float		_rotation;
  Vector3f	_position;
  Vector3f	_target;
};

#endif	//CAMERA_HPP__
