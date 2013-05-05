//
// Camera.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 19:09:38 2013 florian dewulf
// Last update Sun May  5 15:00:45 2013 florian dewulf
//

#ifndef		CAMERA_HPP__
# define	CAMERA_HPP__

#include	<GL/glu.h>
#include	<GL/glut.h>

#include	"GameClock.hpp"
#include	"Input.hpp"
#include	"Vector3f.hpp"

class		Camera
{
public:
  Camera(void);
  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &);
private:
  Vector3f	position_;
  Vector3f	rotation_;
};

#endif	//CAMERA_HPP__
