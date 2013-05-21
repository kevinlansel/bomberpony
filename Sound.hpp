//
// Sound.hpp for bomberpony in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon May 20 15:33:56 2013 gery baudry
// Last update Mon May 20 21:43:26 2013 florian dewulf
//

#ifndef		SOUND_HPP__
# define	SOUND_HPP__

#include	<iostream>
#include	<string>
#include	<SFML/Audio.hpp>

class		Sound
{
public:
  Sound(const std::string &);
  virtual ~Sound();

public:
  void			PlaySound();

public:
  sf::SoundBuffer	getSound();
  void			setSound(std::string &sound);

private:
  sf::SoundBuffer	_menusound;
  sf::Sound		_sound;
};

#endif
