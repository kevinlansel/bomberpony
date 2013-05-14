//
// Camera.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 19:11:14 2013 florian dewulf
// Last update Tue May 14 10:27:13 2013 florian dewulf
//

#include	"Camera.hpp"

Camera::Camera() : _angle(0.0)
{
}

void		Camera::initialize(int sizex, int sizey, const Vector3f &vect, const Vector3f &targ, float rota)
{
  this->_position.x = vect.x;
  this->_position.y = vect.y;
  this->_position.z = vect.z;
  this->_target.x = targ.x;
  this->_target.y = targ.y;
  this->_target.z = targ.z;
  this->_rotation = rota;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(7.0, (float)sizex / (float)sizey, 1.0, 10000.0);
  gluLookAt(this->_position.x, this->_position.y, this->_position.z, targ.x, targ.y, targ.z, 0.0, 1.0, 0.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

void		Camera::update()
{
  this->_angle = (this->_angle + this->_rotation);
  if (this->_angle > 360.0)
    this->_angle = 0;
}

void		Camera::draw()
{
  Vector3f	coord = this->calc_rot();

  this->_position.x = coord.x;
  this->_position.y = coord.y;
  this->_position.z = coord.z;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(7.0, 1024.0 / 768.0, 1.0, 10000.0);
  gluLookAt(this->_position.x, this->_position.y, this->_position.z, this->_target.x, this->_target.y, this->_target.z, 0.0, 1.0, 0.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

Vector3f	Camera::calc_rot() const
{
  Vector3f	vec;
  double	rayon;

  rayon = sqrt(this->_position.x * this->_position.x + this->_position.z * this->_position.z);
  vec.x = rayon * sin(_angle);
  vec.y = this->_position.y;
  vec.z = rayon * cos(_angle);
  return (vec);
}

void		Camera::move(const Vector3f &pos, const Vector3f &target, float angle, float rotation)
{
  this->_angle = angle;
  this->_rotation = rotation;
  this->_position.x = pos.x;
  this->_position.y = pos.y;
  this->_position.z = pos.z;
  this->_target.x = target.x;
  this->_target.y = target.y;
  this->_target.z = target.z;
}

Vector3f	Camera::getPosition() const
{
  return this->_position;
}

Vector3f	Camera::getTarget() const
{
  return this->_target;
}

float		Camera::getAngle() const
{
  return this->_angle;
}

float		Camera::getRotation() const
{
  return this->_rotation;
}
