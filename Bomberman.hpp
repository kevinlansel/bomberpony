//
// Bomberman.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 18:07:32 2013 florian dewulf
// Last update Sat May  4 19:57:24 2013 florian dewulf
//

#ifndef		BOMBERMAN_HPP__
#define		BOMBERMAN_HPP__

#include	<GL/glu.h>
#include	<GL/glut.h>

#include	<list>
#include	"AObject.hpp"
#include	"Game.hpp"
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
};

#endif		// BOMBERMAN_HPP__
