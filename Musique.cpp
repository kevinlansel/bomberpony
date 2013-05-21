//
// Music.cpp for bomberpony in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon May 20 15:33:40 2013 gery baudry
// Last update Tue May 21 15:10:55 2013 florian dewulf
//

#include	"Musique.hpp"

Musique::Musique(const std::string &str)
{
  if (!this->_music.OpenFromFile(str))
    std::cout << "Erreur chargement fichier audio" << std::endl;
  this->_msc = str;
}

Musique::~Musique()
{
}

void			Musique::PlayMusique()
{
  this->_music.Play();
}

void			Musique::StopMusique()
{
  if (this->_music.GetStatus() == sf::Music::Playing)
    this->_music.Stop();
}

void			Musique::setMusique(const std::string &music)
{
  if (this->_msc != music && !this->_music.OpenFromFile(music))
    std::cout << "Erreur chargement fichier audio" << std::endl;
  this->_msc = music;
}
