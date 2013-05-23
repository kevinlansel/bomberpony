//
// Map.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May 18 21:49:18 2013 florian dewulf
// Last update Thu May 23 18:03:05 2013 florian dewulf
//

#ifndef		MAP_HPP__
# define	MAP_HPP__

#include	<list>
#include	<string>
#include        <iostream>
#include        "Utils.hpp"
#include	"File.hpp"

enum            e_map
  {
    OBSTACLE_INCASSABLE,
    OBSTACLE_CASSABLE,
    PLAYER,
    VIDE
  };

class           Map
{
public:
  bool          initialize(int, std::list<std::string> &, int);
  bool          initialize(const std::string &, std::list<std::string> &, unsigned int);

private:
  std::list<std::string>        randomize(unsigned int, std::list<std::string> &);

private:
  std::string                   _filename;
  std::list<std::string>        _list_str;
  unsigned int                  _size;
  unsigned int                  _large;
  unsigned int                  _player;
};

#endif
