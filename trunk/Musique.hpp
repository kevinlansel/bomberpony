//
// Sound.hpp for bomberpony in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon May 20 15:33:56 2013 gery baudry
// Last update Tue May 21 11:37:57 2013 gery baudry
//

#ifndef		MUSIQUE_HPP__
# define	MUSIQUE_HPP__

#include	<iostream>
#include	<string>
#include	<SFML/Audio.hpp>

class		Musique
{
public:
  Musique(const std::string &);
  virtual ~Musique();

public:
  void			PlayMusique();

public:
  void			setMusique(const std::string &music);

private:
  sf::Music		_music;
  std::string		_msc;
};

#endif
