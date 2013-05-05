//
// AObject.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 19:02:44 2013 florian dewulf
// Last update Sat May  4 19:05:26 2013 florian dewulf
//

#ifndef		AOBJECT_HPP__
# define	AOBJECT_HPP__

#include	"Game.hpp"
#include	"GameClock.hpp"
#include	"Input.hpp"
#include	"Vector3f.hpp"

class		AObject
{
public:
  AObject();
  virtual	~AObject();

public:
  virtual void	initialize() = 0;
  virtual void	update(gdl::GameClock const &, gdl::Input &) = 0;
  virtual void	draw() = 0;

protected:
  Vector3f	position_;
  Vector3f	rotation_;
};

#endif	//AOBJECT_HPP__
