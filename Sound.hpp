//
// Sound.hpp for bomberpony in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon May 20 15:33:56 2013 gery baudry
// Last update Mon May 20 15:45:04 2013 gery baudry
//

#include	<SFML/Audio.hpp>
#include	<iostream>

class		Sound
{
public:
  Sound();
  virtual ~Sound();

public:
  void			Playsound();

public:
  SoundBuffer		getSound();
  void			setSound(std::string &sound);

private:
  SoundBuffer		_menusound;
};
