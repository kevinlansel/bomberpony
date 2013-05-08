//
// Bomberman.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sun May  5 14:03:36 2013 florian dewulf
// Last update Tue May  7 21:56:56 2013 florian dewulf
//

#include	"Bomberman.hpp"

Bomberman::Bomberman()
{
  //this->objects_.push_back(new Triangle);
  //this->objects_.push_back(new Rectangle);
}

Bomberman::~Bomberman()
{
}

void		Bomberman::initialize()
{
  this->window_.create();
  this->camera_.initialize();
  this->_model = gdl::Model::load("./ressource/marvin.fbx");
  this->objects_.push_back(new Cube(Vector3f(-400, 0, -400), Vector3f(400, -5, 400), "./ressource/toto.tga"));
  this->objects_.push_back(new Cube(Vector3f(-250, 50, 150), Vector3f(-200, 0, 100), "./ressource/carreaux.tga"));
  this->objects_.push_back(new Cube(Vector3f(-150, 50, 150), Vector3f(-100, 0, 100), "./ressource/carreaux.tga"));
  this->objects_.push_back(new Cube(Vector3f(-50, 50, 150), Vector3f(0, 0, 100), "./ressource/carreaux.tga"));
  this->objects_.push_back(new Cube(Vector3f(50, 50, 150), Vector3f(100, 0, 100), "./ressource/carreaux.tga"));
  this->objects_.push_back(new Cube(Vector3f(150, 50, 150), Vector3f(200, 0, 100), "./ressource/carreaux.tga"));
  this->objects_.push_back(new Pyramide(Vector3f(-150, 0, -150), Vector3f(150, -50, 0), Vector3f(0, 0, 150), Vector3f(0, 150, 0)));
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->initialize();
  this->_model.infos();
}

void		Bomberman::update()
{
  this->_model.update(gameClock_);
  this->_model.play("Take 001");
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->update(gameClock_, input_);
  camera_.update(gameClock_, input_);
}

void		Bomberman::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  //glEnable(GL_TEXTURE_3D);
  //glColor3f(0.0, 0.0, 1.0);
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(0.0, 0.0, 0.0);
  this->_model.draw_immediate();
  glPopMatrix();
  //glDisable(GL_TEXTURE_3D);
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->draw();
}

void		Bomberman::unload()
{
}
