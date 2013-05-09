//
// Bomberman.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sun May  5 14:03:36 2013 florian dewulf
// Last update Thu May  9 15:22:28 2013 florian dewulf
//

#include	"Bomberman.hpp"

Bomberman::Bomberman() : _scene(new Menu(Vector3f(0, 2000, 6000), Vector3f(0, 200, 0)))
{
  //this->objects_.push_back(new Triangle);
  //this->objects_.push_back(new Rectangle);
}

Bomberman::~Bomberman()
{
  delete this->_scene;
}

void		Bomberman::initialize()
{
  this->window_.create();
  this->camera_.initialize(1024, 768, this->_scene->getPoscam(), this->_scene->getTarget(), 0.01);
  /*this->_model = gdl::Model::load("./ressource/marvin.fbx");*/
  this->objects_.push_back(new Cube(Vector3f(-400, 0, -400), Vector3f(400, -5, 400), "./ressource/toto.tga"));
  this->objects_.push_back(new Cube(Vector3f(-250, 50, 150), Vector3f(-200, 0, 100), "./ressource/carreaux.tga"));
  this->objects_.push_back(new Cube(Vector3f(-150, 50, 150), Vector3f(-100, 0, 100), "./ressource/carreaux.tga"));
  this->objects_.push_back(new Cube(Vector3f(-50, 50, 150), Vector3f(0, 0, 100), "./ressource/carreaux.tga"));
  this->objects_.push_back(new Cube(Vector3f(50, 50, 150), Vector3f(100, 0, 100), "./ressource/carreaux.tga"));
  this->objects_.push_back(new Cube(Vector3f(150, 50, 150), Vector3f(200, 0, 100), "./ressource/carreaux.tga"));
  /*this->objects_.push_back(new Pyramide(Vector3f(-150, 0, -150), Vector3f(150, -50, 0), Vector3f(0, 0, 150), Vector3f(0, 150, 0)));*/
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->initialize();
  this->_scene->initialize("./ressource/marvin.fbx");
}

void		Bomberman::update()
{
  /*
  this->_model.update(gameClock_);
  this->_model.play("Take 001");
  */
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->update(gameClock_, input_);
  this->_scene->update(gameClock_);
  camera_.update(gameClock_, input_);
}

void		Bomberman::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(255.0f, 255.0f, 255.0f, 1.0f);
  glClearDepth(1.0f);
  this->camera_.draw();
  this->_scene->draw();
  /*
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(0.0, 0.0, 0.0);
  this->_model.draw_immediate();
  glPopMatrix();
  */
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->draw();
}

void		Bomberman::unload()
{
}
