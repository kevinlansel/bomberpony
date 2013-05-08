//
// Bomberman.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 18:07:32 2013 florian dewulf
// Last update Mon May  6 19:52:31 2013 florian dewulf
//

#ifndef		BOMBERMAN_HPP__
#define		BOMBERMAN_HPP__

#include	<GL/glu.h>
#include	<GL/glut.h>

#include	<list>
#include	"AObject.hpp"
#include	"Game.hpp"
#include	"Model.hpp"
#include	"Camera.hpp"
#include	"Forme.hpp"

class           Bomberman : public gdl::Game
{
public:
  Bomberman();
  virtual	~Bomberman();

public:
  void		initialize();
  void		update();
  void		draw();
  void		unload();

public:
  Camera		camera_;
  std::list<AObject *>	objects_;
  gdl::Model		_model;
};

#endif		// BOMBERMAN_HPP__
