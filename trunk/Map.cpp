//
// Map.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May 18 21:49:08 2013 florian dewulf
// Last update Sat May 18 22:59:11 2013 florian dewulf
//

#include	"Map.hpp"

bool		Map::initialize(int size_random, const std::list<std::string> &liste, int nb_joueur)
{
  if (this->_size < 10)
    return false;
  this->_size = size_random;
  this->randomize();
}

bool		Map::initialize(const std::string &str, std::list<std::string> &liste, int nb_joueur)
{
  this->_size = Utils::StringToInt(liste.first());
  if (liste.size() < 10 || this->_size < 10 || this->_size != liste.size() - 1)
    return false;
  //check la taille de chaque string
  //check si y'a des rebords, sinon les ajouter
  //check si y'a bien nb_joueur zone de pop
}

void		Map::randomize()
{
}
