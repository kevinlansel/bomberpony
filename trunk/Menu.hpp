//
// Menu.hpp for  in /home/lund/Projets/bomberpony/libgdl_gl-2012.4
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Wed May  8 17:57:34 2013 florian dewulf
// Last update Mon May 13 17:22:45 2013 florian dewulf
//

#ifndef		MENU_HPP__
# define	MENU_HPP__

#include	<GL/glu.h>
#include	<GL/glut.h>

#include	<iostream>
#include	<string>

#include	"Bomberman.h"
#include	"Camera.hpp"
#include	"Forme.hpp"
#include	"Input.hpp"
#include	"Vector3f.hpp"
#include	"GameClock.hpp"
#include	"Scene.hpp"
#include	"Model.hpp"
#include	"Text.hpp"

class		Menu : public Scene
{
public:
  Menu(const Vector3f &, const Vector3f &, MenuType);
  virtual	~Menu();

public:
  virtual void	initialize(const std::string &);
  virtual void	draw();
  virtual void	update(gdl::GameClock &, gdl::Input &);
  MenuType	getChoice() const;

private:
  float		move(float, gdl::GameClock &, gdl::Input &);

private:
  AObject	*_background;
  Camera	_camera;
  Triangle	_cursor;
  MenuType	_choice;
};

#endif
