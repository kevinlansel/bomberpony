//
// Sound.hpp for bomberpony in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon May 20 15:33:56 2013 gery baudry
// Last update Tue May 21 10:31:25 2013 gery baudry
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
  void			setSound(const std::string &sound);

private:
  sf::SoundBuffer	_menusound;
  sf::Sound		_sound;
  std::string		_snd;
};

#endif
