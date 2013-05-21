//
// Controller.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 15:52:26 2013 florian dewulf
// Last update Tue May 21 00:15:07 2013 florian dewulf
//

#ifndef		CONTROLLER_HPP__
# define	CONTROLLER_HPP__

#include	<list>
#include	<map>
#include	<string>
#include	<vector>
#include	<sstream>

#include	"Bomberman.h"
#include	"Menu.hpp"
#include	"Scene.hpp"
#include	"GameClock.hpp"
#include	"Input.hpp"
#include	"File.hpp"
#include	"Utils.hpp"

class		Controller
{
public:
  Controller();
  virtual	~Controller();

public:
  struct		Score
  {
    std::string		_player;
    unsigned int	_score;
  };

public:
  void		initialize();
  void		Majmap();		// modif _map
  void		Majscore();		// modif the _score_list
  bool		update(gdl::GameClock &, gdl::Input &);
  void		draw();
  void		changeScene(const Vector3f &, const Vector3f &, MenuType, std::vector<int> &);

private:
  void		setText();

private:
  MenuType	changeSound(const MenuType &);
  MenuType	changeTypeMap(const MenuType &);
  MenuType	changeIA(const MenuType &);
  MenuType	loadGame(const MenuType &);
  MenuType	launchGame(const MenuType &);
  MenuType	incOption(const MenuType &);
  MenuType	decOption(const MenuType &);
  void		changeMap();

private:
  Scene					*_scene;	// Menu or game
  bool					_sound;		// true = on, false = off
  bool					_map_choice;	// true = random, false = predef
  std::string				_map_option;	// if it's random = the size, else the name of the file
  MenuType				_screen;	// type of scene
  int					_ia;
  unsigned int				_offset;
  std::list<Score>			_score_list;	// list of the score
  std::list<std::string>		_map;		// list of the map in the folder map
  std::map<MenuType, std::vector<int> >	_map_menu;	// arg to pass to the menu
  std::map<MenuType, MenuType (Controller::*)(const MenuType &)>	_ptr_func;	// ptr on a func to modify information
};

#endif
