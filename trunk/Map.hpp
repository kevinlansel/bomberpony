//
// Map.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May 18 21:49:18 2013 florian dewulf
// Last update Sat May 18 22:54:06 2013 florian dewulf
//

#ifndef		MAP_HPP__
# define	MAP_HPP__

#include	<list>
#include	<string>

class		Map
{
public:
  bool		initialize(int, const std::list<std::string> &, int);
  bool		initialize(const std::string &, std::list<std::string> &, int);

private:
  std::list<std::string>	randomize();

private:
  std::string			_filename;
  std::list<std::string>	_list_str;
  unsigned int			_size;
};

#endif
