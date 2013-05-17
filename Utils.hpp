//
// Utils.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Fri May 17 15:47:11 2013 florian dewulf
// Last update Fri May 17 15:52:44 2013 florian dewulf
//

#ifndef		UTILS_HPP__
# define	UTILS_HPP__

#include	<iostream>
#include	<string>
#include	<sstream>

class		Utils
{
public:
  template <typename T>
  static std::string	expandString(const std::string &, T &);
};

std::string		expandString(const std::string &str, T &value)
{
  std::stringstream	ss;

  ss.str(str);
  ss << value;
  return ss.str();
}

#endif
