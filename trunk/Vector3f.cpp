//
// Vector3f.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 19:07:59 2013 florian dewulf
// Last update Sun May 12 19:03:54 2013 florian dewulf
//

#include	"Vector3f.hpp"

Vector3f::Vector3f() : x(0), y(0), z(0)
{
}

Vector3f::Vector3f(float a, float b, float c) : x(a), y(b), z(c)
{
}

Vector3f::Vector3f(const Vector3f &vec) : x(vec.x), y(vec.y), z(vec.z)
{
}
