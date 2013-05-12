//
// File.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May 11 16:25:00 2013 florian dewulf
// Last update Sat May 11 20:56:30 2013 florian dewulf
//

#include	"File.hpp"

File::File() : _map(false)
{
  if (access("./map/", R_OK | F_OK) != -1)
    this->_map = true;
}

File::~File()
{
}

std::list<std::string>	File::ls()
{
  DIR				*dir;
  struct dirent			*st;
  std::list<std::string>	list;

  if (this->_map)
    {
      dir = opendir("./map/");
      if (dir == NULL)
	return list;
      while ((st = readdir(dir)))
	{
	  std::string	str(st->d_name);
	  if (str != "." && str != "..")
	    list.push_back(str);
	}
      closedir(dir);
    }
  return (list);
}

bool		File::getStatemap() const
{
  return (this->_map);
}

std::list<std::string>	File::getFileContent() const
{
  std::ifstream		file(".score");
  std::string		str;
  std::list<std::string>	list;

  if (file.is_open())
    {
      while (file.good())
	{
	  getline(file, str);
	  list.push_back(str);
	}
      file.close();
    }
  return list;
}

void		File::putFile(const std::string &str, const std::list<std::string> &list)
{
  std::ofstream	out(str.c_str());

  if (out.is_open())
    {
      for (std::list<std::string>::const_iterator it = list.begin() ; it != list.end() ; ++it)
	out << *it << std::endl;
      out.close();
    }
}
