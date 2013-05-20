//
// APlayer.cpp for bomberman in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu May  9 11:21:55 2013 gery baudry
// Last update Mon May 20 11:23:49 2013 gery baudry
//

#include	"APlayer.hpp"

APlayer::APlayer(int joueur, const std::string &name) : _pos(0, 0, 0), _joueur(joueur), _bomb(1), _name(name), _alive(true)
{
}

APlayer::~APlayer()
{
}

void			APlayer::initialize()
{
  this->_model = gdl::Model::load("./marvin.fbx");
}

void			APlayer::draw()
{
  gdlClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.74f, 0.84f, 98.0f, 1.0f);
  glClearDepth(1.0f);
  this->_model.draw();
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

Vector3f		APlayer::getTranslation() const
{
  return (this->_translation);
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

void			APlayer::setTranslation(Vector3f trans)
{
  this->_translation.x = trans.x;
  this->_translation.y = trans.y;
  this->_translation.z = trans.z;
}
