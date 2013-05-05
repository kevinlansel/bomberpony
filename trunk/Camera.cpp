//
// Camera.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 19:11:14 2013 florian dewulf
// Last update Sun May  5 15:23:31 2013 florian dewulf
//

#include	"Camera.hpp"

Camera::Camera() : position_(0.0, 3000.0, 5900.0), rotation_(30.0, 0.0, 0.0)
{
}

void		Camera::initialize(void)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(7.0, 800.0/600.0, 1.0, 10000.0);
  gluLookAt(this->position_.x, this->position_.y, this->position_.z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

void		Camera::update(gdl::GameClock const &gameClock, gdl::Input &input)
{
}
