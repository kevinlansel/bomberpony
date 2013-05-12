//
// Vector3f.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 19:06:39 2013 florian dewulf
// Last update Sun May 12 19:03:22 2013 florian dewulf
//

#ifndef		VECTOR3F_HPP__
# define	VECTOR3F_HPP__

struct		Vector3f
{
  float		x;
  float		y;
  float		z;

  Vector3f();
  Vector3f(float, float, float);
  Vector3f(const Vector3f &);
};

#endif	//VECTOR3F_HPP__
