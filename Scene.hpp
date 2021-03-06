//
// Scene.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Wed May  8 19:59:03 2013 florian dewulf
// Last update Tue May 21 14:48:09 2013 florian dewulf
//

#ifndef		SCENE_HPP__
# define	SCENE_HPP__

#include	<string>

#include	"Vector3f.hpp"

#include	"Bomberman.h"
#include	"Input.hpp"
#include	"GameClock.hpp"
#include	"Color.hpp"
#include	"Text.hpp"

class		Scene
{
public:
  Scene(const Vector3f &, const Vector3f &);
  virtual	~Scene();

public:
  virtual void	initialize(const std::string &, const Vector3f &, const Vector3f &) = 0;
  virtual void	draw() = 0;
  virtual MenuType	update(gdl::GameClock &, gdl::Input &, bool) = 0;

public:
  void		setTxt(const std::string &, unsigned int, unsigned int);
  void		setColor(int, int, int);
  void		setColorRed();
  void		setColorGreen();
  void		setColorBlue();

public:
  Vector3f	getPoscam() const;
  Vector3f	getTarget() const;
  void		setPoscam(const Vector3f &);

protected:
  Vector3f	_poscam;
  Vector3f	_target;
  gdl::Text	_txt;
};

#endif
