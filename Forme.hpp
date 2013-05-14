//
// Forme.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 19:50:30 2013 florian dewulf
// Last update Tue May 14 10:36:05 2013 florian dewulf
//

#ifndef		FORME_HPP__
# define	FORME_HPP__

#include	<GL/glu.h>
#include	<GL/glut.h>
#include	<string>
#include	<iostream>

#include	"Image.hpp"
#include	"AObject.hpp"
#include	"Vector3f.hpp"

/* ------------ */

class		Triangle : public AObject
{
public:
  Triangle(const Vector3f &, const Vector3f &, const Vector3f &, const Vector3f &);
  void		initialize();
  void		update();
  void		draw();
  void		setTranslation(const Vector3f &);
  Vector3f	getTranslation() const;

private:
  Vector3f	_pt1;
  Vector3f	_pt2;
  Vector3f	_pt3;
  Vector3f	_color;
  float		_rotation;
  Vector3f	_translation;
};

/* ------------ */

class		Rectangle : public AObject
{
public:
  Rectangle();
  virtual	~Rectangle();

  /*public:
  void		initialize();
  void		update(gdl::GameClock const &, gdl::Input &);
  void		draw(void);*/
public:
  static void	draw_rect(const Vector3f &, const Vector3f &, float, float, float);
  static void	draw_rect(const Vector3f &, const Vector3f &, gdl::Image &);
  static void	draw_plan(const Vector3f &, const Vector3f &, float, float, float);
  static void	draw_plan(const Vector3f &, const Vector3f &, gdl::Image &);

};

/* ------------ */

class		Cube : public AObject
{
public:
  Cube(const Vector3f &, const Vector3f &, const std::string &texture = "");
  virtual	~Cube();

public:
  void		initialize();
  void		update();
  void		draw(void);

private:
  Vector3f	_origin;
  Vector3f	_opposite;
  gdl::Image	_texture;
  bool		_stateTexture;
};

/* ------------ */

class		Pyramide : public AObject
{
public:
  Pyramide(const Vector3f &, const Vector3f &, const Vector3f &, const Vector3f &);
  virtual	~Pyramide();

public:
  void		initialize();
  void		update();
  void		draw(void);

private:
  Vector3f	_v1;
  Vector3f	_v2;
  Vector3f	_v3;
  Vector3f	_sommet;
  Vector3f	_rotation;
};

#endif
