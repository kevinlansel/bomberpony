//
// Sound.cpp for bomberpony in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon May 20 15:33:40 2013 gery baudry
// Last update Tue May 21 10:42:29 2013 gery baudry
//

#include	"Sound.hpp"

Sound::Sound(const std::string &str)
{
  if (!this->_menusound.LoadFromFile(str))
    std::cout << "Erreur chargement fichier audio" << std::endl;
  this->_snd = str;
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

void			Sound::setSound(const std::string &sound)
{
  std::cout << sound << std::endl << this->_snd << std::endl;
  if (this->_snd != sound && !this->_menusound.LoadFromFile(sound))
    std::cout << "Erreur chargement fichier audio" << std::endl;
  this->_snd = sound;
}
