//
// Menu.hpp for  in /home/lund/Projets/bomberpony/libgdl_gl-2012.4
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Wed May  8 17:57:34 2013 florian dewulf
// Last update Tue May 21 14:47:52 2013 florian dewulf
//

#ifndef		MENU_HPP__
# define	MENU_HPP__

#include	<GL/glu.h>
#include	<GL/glut.h>

#include	<map>
#include	<iostream>
#include	<string>
#include	<vector>

#include	"Sound.hpp"
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
  Menu(const Vector3f &, const Vector3f &, MenuType, const std::vector<int> &);
  virtual	~Menu();

public:
  virtual void	initialize(const std::string &, const Vector3f &, const Vector3f &);
  virtual void	draw();
  virtual MenuType	update(gdl::GameClock &, gdl::Input &, bool);
  MenuType	getChoice() const;

private:
  MenuType	move(float &, gdl::GameClock &, gdl::Input &, bool);
  void		inc_choice();
  void		dec_choice();
  MenuType	change_option(gdl::Input &, float &, gdl::GameClock &);

private:
  Cube		*_background;
  Camera	_camera;
  Triangle	_cursor;
  int		_choice;
  Vector3f	_limit_down;
  Vector3f	_limit_up;
  std::vector<int>	_list;
  Sound		_snd_move;
  Sound		_snd_enter;
};

#endif
