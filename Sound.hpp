//
// Sound.hpp for bomberpony in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon May 20 15:33:56 2013 gery baudry
// Last update Mon May 20 17:18:52 2013 florian dewulf
//

#ifndef		SOUND_HPP__
# define	SOUND_HPP__

#include	<SFML/Audio.hpp>
#include	<iostream>

class		Sound
{
public:
  Sound();
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
