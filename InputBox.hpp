//
// InputBox.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Fri May 24 21:06:32 2013 florian dewulf
// Last update Sun May 26 18:41:41 2013 florian dewulf
//

#ifndef		INPUTBOX_HPP__
# define	INPUTBOX_HPP__

#include	<string>

#include	"GameClock.hpp"
#include	"Input.hpp"
#include	"Model.hpp"

#include	"Utils.hpp"
#include	"Forme.hpp"
#include	"Bomberman.h"
#include	"Scene.hpp"
#include	"Vector3f.hpp"

class		InputBox : public Scene
{
public:
  InputBox(MenuType);
  virtual	~InputBox();

  virtual void		initialize(const std::string &, const Vector3f &, const Vector3f &);
  virtual MenuType	update(gdl::GameClock &, gdl::Input &, bool);
  virtual void		draw();

private:
  void			UpColor();
  void			DownColor();
  void			addChar(char);
  void			reduceStr();
  void			mouvement(gdl::Input &);
  void			mouv_lateral(gdl::Input &);
  void			mouv_vertical(gdl::Input &);

private:
  int		_player;
  std::string	_strJ1;
  std::string	_strJ2;
  bool		_state;
  int		_count;
  float		_last_time;
  int		_curs;

private:
  Vector3f	_colorJ1;
  Vector3f	_colorJ2;
};

#endif
