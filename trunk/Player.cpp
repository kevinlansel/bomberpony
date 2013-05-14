//
// Player.cpp for bomberman in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu May  9 11:21:55 2013 gery baudry
// Last update Tue May 14 11:37:25 2013 florian dewulf
//

#include	"Player.hpp"

Player::Player(int joueur, const std::string &name) : APlayer(joueur, name)
{
}

Player::~Player()
{
}

void		Player::update(gdl::Input &input)
{
  if (this->_joueur == 1)
    move_player_one(input);
  else if (this->_joueur == 2)
    move_player_two(input);
  if (input.isKeyDown(gdl::Keys::F1) == true)
    //save les infos
  if (input.isKeyDown(gdl::Keys::P) == true)
    //image pose +menu
}

void		Player::move_player_one(gdl::Input &input)
{
  if (input.isKeyDown(gdl::Keys::Right) == true)
    this->_pos.x += 1;
  if (input.isKeyDown(gdl::Keys::Left) == true)
    this->_pos.x -= 1;
  if (input.isKeyDown(gdl::Keys::Up) == true)
    this->_pos.z -= 1;
  if (input.isKeyDown(gdl::Keys::Down) == true)
    this->_pos.z += 1;
  if (input.isKeyDown(gdl::Keys::RControl) == true && this->_bomb != 0)
    //pose la bombinette && décrémente le nbr de bombe
    //appel a la fonction affichage
    //fonction timer pour explosion + accrémentation une fois la bombe explosé
}

void		Player::move_player_two(gdl::Input &input)
{
  if (input.isKeyDown(gdl::Keys::D) == true)
    this->_pos.x += 1;
  if (input.isKeyDown(gdl::Keys::Q) == true)
    this->_pos.x -= 1;
  if (input.isKeyDown(gdl::Keys::Z) == true)
    this->_pos.z -= 1;
  if (input.isKeyDown(gdl::Keys::S) == true)
    this->_pos.z += 1;
  if (input.isKeyDown(gdl::Keys::LControl) == true && this->_bomb != 0)
    //pose la bombinette && décrémente le nombre de bombe
    //appel a la fonction affichage
    //fonction timer pour explosion + accrémentation une fois la bombe explosé
}
