//
// Sound.cpp for bomberpony in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon May 20 15:33:40 2013 gery baudry
// Last update Mon May 20 17:19:04 2013 florian dewulf
//

#include	"Sound.hpp"

Sound::Sound()
{
  if (!this->_menusound.LoadFromFile("./ressource/fart.wav"))
    std::cout << "Erreur chargement fichier audio" << std::endl;
}

Sound::~Sound()
{
}

void			Sound::PlaySound()
{
  this->_sound.SetBuffer(this->_menusound);
  this->_sound.Play();
}

sf::SoundBuffer		Sound::getSound()
{
  return (this->_menusound);
}

void			Sound::setSound(std::string &sound)
{
  if (this->_menusound.LoadFromFile(sound))
    std::cout << "Erreur chargement fichier audio" << std::endl;
}
