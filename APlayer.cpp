//
// APlayer.cpp for bomberman in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu May  9 11:21:55 2013 gery baudry
// Last update Tue May 14 11:15:24 2013 gery baudry
//

#include	"APlayer.hpp"

APlayer::APlayer(int joueur, const std::string &name) : _pos(0, 0, 0), _joueur(joueur), _bomb(1), _name(name), _alive(true)
{
}

APlayer::~APlayer()
{
}

void		APlayer::move_player_one(gdl::Input &input)
{
  if (input.isKeyDown(gdl::Keys::Right) == true)
    this->_winx += 1;
  if (input.isKeyDown(gdl::Keys::Left) == true)
    this->_winx -= 1;
  if (input.isKeyDown(gdl::Keys::Up) == true)
    this->_winy -= 1;
  if (input.isKeyDown(gdl::Keys::Down) == true)
    this->_winy += 1;
  if (input.isKeyDown(gdl::Keys::RControl) == true && this->_bomb != 0)
    //pose la bombinette && décrémente le nbr de bombe
    //appel a la fonction affichage
    //fonction timer pour explosion + accrémentation une fois la bombe explosé
}

void		APlayer::move_player_two(gdl::Input &input)
{
  if (input.isKeyDown(gdl::Keys::D) == true)
    this->_winx += 1;
  if (input.isKeyDown(gdl::Keys::Q) == true)
    this->_winx -= 1;
  if (input.isKeyDown(gdl::Keys::Z) == true)
    this->_winy -= 1;
  if (input.isKeyDown(gdl::Keys::S) == true)
    this->_winy += 1;
  if (input.isKeyDown(gdl::Keys::LControl) == true && this->_bomb != 0)
    //pose la bombinette && décrémente le nombre de bombe
    //appel a la fonction affichage
    //fonction timer pour explosion + accrémentation une fois la bombe explosé
}

//
//		Getter
//

Vector3f		APlayer::getPos() const
{
  return (this->_pos);
}

int			APlayer::getJoueur() const
{
  return (this->_joueur);
}

int			APlayer::getBomb() const
{
  return (this->_bomb);
}

std::string		APlayer::getName() const
{
  return (this->_name);
}

bool			APlayer::getAlive() const
{
  return (this->_alive);
}

//
//		Setter
//

void			APlayer::setPos(Vector3f pos)
{
  this->_pos = pos;
}

void			APlayer::setJoueur(int joueur)
{
  this->_joueur = joueur;
}

void			APlayer::setBomb(int bomb)
{
  this->_bomb = bomb;
}

void			APlayer::setName(std::string &name)
{
  this->_name = name;
}

void			APlayer::setAlive(bool alive)
{
  this->_alive = alive;
}
