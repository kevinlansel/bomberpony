//
// Scene.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Wed May  8 22:05:21 2013 florian dewulf
// Last update Fri May 17 22:44:43 2013 florian dewulf
//

#include	"Scene.hpp"

Scene::Scene(const Vector3f &vec, const Vector3f &target) : _poscam(vec.x, vec.y, vec.z), _target(target.x, target.y, target.z)
{
}

Scene::~Scene()
{
}

void		Scene::setTxt(const std::string &str, unsigned int x, unsigned int y)
{
  this->_txt.setText(str);
  this->_txt.setPosition(x, y);
}

void		Scene::setColor(int r, int g, int b)
{
  this->_txt.setColor(gdl::Color(r, g, b));
}

void		Scene::setColorRed()
{
  this->setColor(255, 0, 0);
}

void		Scene::setColorGreen()
{
  this->setColor(0, 255, 0);
}

void		Scene::setColorBlue()
{
  this->setColor(0, 0, 255);
}

Vector3f	Scene::getPoscam() const
{
  return (this->_poscam);
}

Vector3f	Scene::getTarget() const
{
  return (this->_target);
}

void		Scene::setPoscam(const Vector3f &vec)
{
  this->_poscam = vec;
}
