//
// Map.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May 18 21:49:08 2013 florian dewulf
// Last update Thu May 23 18:11:04 2013 florian dewulf
//

#include	"Map.hpp"

bool		Map::initialize(int size_random,  std::list<std::string> &liste,
				int nb_joueur)
{
  this->_size = size_random;
  if (this->_size < 10)
    return false;
  this->randomize(this->_size, liste);
  return true;
}

bool		Map::initialize(const std::string &str, std::list<std::string> &list,
				unsigned int nb_joueur)
{
  std::string                           tmp;
  unsigned int                          i;
  File					file;
  std::list<std::string>		liste = file.getFileContent("map/" + str);
  std::list<std::string>::iterator      it = liste.begin();

  this->_player = 0;
  if (it == liste.end())
    return false;
  this->_size = Utils::StringToInt(*it);
  it++;
  if (it != liste.end())
    {
      tmp = *it;
      this->_large = tmp.length();
    }
  if (this->_size != this->_large || liste.size() != this->_size + 1 || this->_size < 10)
    {
      std::cout << "incorect size map, expected "  << this->_size + 1
		<< " line(s)"<< std::endl;
      return false;
    }
  while (it != liste.end())
    {
      tmp = *it;
      i = 0;
      if (tmp.length() != this->_large)
        return false;
      while (i != tmp.length())
        {
          if (tmp[i] == PLAYER + '0')
            this->_player += 1;
	  i++;
        }
      list.push_back(tmp);
      it++;
    }
  if (this->_player < nb_joueur)
    {
      std::cout << "incorect number of player in this map " << this->_player
		<< " ,the correct number is " << nb_joueur  << std::endl;
      return false;
    }
  std::cout << "return true" << std::endl;
  return true;
}

std::list<std::string>		Map::randomize(unsigned int size, std::list<std::string> &liste)
{
  unsigned int				i = 0;
  unsigned int				j = 1;
  unsigned int				k = 0;
  std::list<std::string>		list;
  std::list<std::string>::iterator      it = list.begin();
  std::string				pattern;

  list.push_back("10001");
  list.push_back("01010");
  list.push_back("00200");
  list.push_back("10001");
  list.push_back("01010");
  while (i != size)
    {
      j = 1;
      std::string	tmp = "";
      tmp[0] = '1';
      while (j != size)
	{
	  k = 0;
	  if (it == list.end())
	    it = list.begin();
	  pattern = *it;
	  while (k != pattern.size() - 1 && j != size)
	    {
	      tmp +=  pattern[k];
	      j++;
	      k++;
	    }
	}
      it++;
      liste.push_back(tmp);
      i++;
    }
  return liste;
}
