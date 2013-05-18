//
// Utils.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Fri May 17 15:47:11 2013 florian dewulf
// Last update Sat May 18 13:13:21 2013 florian dewulf
//

#ifndef		UTILS_HPP__
# define	UTILS_HPP__

#include	<iostream>
#include	<string>
#include	<sstream>
#include	<list>
#include	<vector>

#include	"APlayer.hpp"
#include	"Player.hpp"
#include	"Bot.hpp"

class		Utils
{
public:
  template <typename T>
  static std::string	expandString(const std::string &, T &);

  static int		StringToInt(const std::string &);
  static bool		ParsePlayer(std::list<std::string>::const_iterator &, std::list<APlayer *> &);
};

std::string		Utils::expandString(const std::string &str, T &value)
{
  std::stringstream	ss;

  ss.str(str);
  ss << value;
  return ss.str();
}

int			Utils::StringToInt(const std::string &str)
{
  std::stringstream	ss;
  int			nb;

  ss.str(str);
  ss >> nb;
  return nb;
}

bool			Utils::ParsePlayer(std::list<std::string>::const_iterator &it, std::list<APlayer *> &_players)
{
  std::vector		vec;
  int			i;
  Vector3f		pos;
  APlayer		*pl;

  if (it->find("pos:") == 0 && it->find(":x:") == 3 && it->find("y:") != std::string::npos && it->find("z:") != std::string::npos && it->find("y:") < it->find("z:"))
    {
      pos.x = Utils::StringToInt(it->substr(it->find(":x:") + 3, it->find("y:") - it->find(":x:") + 3));
      pos.y = Utils::StringToInt(it->substr(it->find("y:") + 2, it->find("z:") - it->find("y:") + 2));
      pos.z = Utils::StringToInt(it->substr(it->find("z:") + 2, it->size()));
    }
  else
    return (false);
  ++it;

  if (it->find("joueur:") == 0)
    i = Utils::StringToInt(it->substr(it->find("joueur:") + 6));
  else
    return (false);
  ++it

  if (i == -1)
    pl = new Bot(Utils::StringToInt(*it));//et le vector en param non ?
  else if ((i == 1 || i == 2) && it->find("name:") == 0)
    pl = new Player(i, it->substr(5));//et le vector en param non ?
  else
    return (false);
  ++it;

  while (it->find("bomb:") == 0)
    {
      pl->addBomb();//...
      ++it;
    }

  if (it->find("alive:") == 0)
    pl->setAlive((it->substr(6) == "true") ? true : false);
  else
    {
      delete pl;
      return false;
    }
  _players.push_back(pl);
  return true;
}

#endif
