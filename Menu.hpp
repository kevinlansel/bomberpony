//
// Menu.hpp for  in /home/lund/Projets/bomberpony/libgdl_gl-2012.4
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Wed May  8 17:57:34 2013 florian dewulf
// Last update Tue May 14 10:38:50 2013 florian dewulf
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
  Menu(const Vector3f &, const Vector3f &, MenuType, MenuType);
  virtual	~Menu();

public:
  virtual void	initialize(const std::string &, const Vector3f &, const Vector3f &);
  virtual void	draw();
  virtual void	update(gdl::GameClock &, gdl::Input &);
  MenuType	getChoice() const;

private:
  void		move(float &, gdl::GameClock &, gdl::Input &);
  void		inc_choice();
  void		dec_choice();

private:
  Cube		*_background;
  Camera	_camera;
  Triangle	_cursor;
  MenuType	_choice;
  MenuType	_limit_choice;
  Vector3f	_limit_down;
  Vector3f	_limit_up;
};

#endif
