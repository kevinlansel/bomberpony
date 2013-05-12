//
// File.hpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May 11 17:49:29 2013 florian dewulf
// Last update Sat May 11 20:02:02 2013 florian dewulf
//

#ifndef		FILE_HPP__
# define	FILE_HPP__

#include	<sys/types.h>
#include	<dirent.h>
#include	<unistd.h>

#include	<iostream>
#include	<fstream>
#include	<list>
#include	<string>

class		File
{
public:
  File();
  virtual	~File();

public:
  std::list<std::string>	ls();
  bool				getStatemap() const;
  std::list<std::string>	getFileContent() const;
  void				putFile(const std::string &, const std::list<std::string> &);

private:
  bool		_map;
};

#endif
