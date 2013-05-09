//
// Menu.hpp for  in /home/lund/Projets/bomberpony/libgdl_gl-2012.4
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Wed May  8 17:57:34 2013 florian dewulf
// Last update Thu May  9 15:12:54 2013 florian dewulf
//

#ifndef		MENU_HPP__
# define	MENU_HPP__

#include	<GL/glu.h>
#include	<GL/glut.h>

#include	<iostream>
#include	<string>

#include	"Vector3f.hpp"
#include	"GameClock.hpp"
#include	"Scene.hpp"
#include	"Model.hpp"
#include	"Text.hpp"

class		Menu : public Scene
{
public:
  Menu(const Vector3f &, const Vector3f &);
  virtual	~Menu();

public:
  virtual void	initialize(const std::string &);
  virtual void	draw();
  virtual void	update(gdl::GameClock &);

private:
  gdl::Model	_background;
};

#endif
