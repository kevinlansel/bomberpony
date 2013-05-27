//
// Bomberman.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sun May  5 14:03:36 2013 florian dewulf
// Last update Sun May 26 03:47:19 2013 florian dewulf
//

#include	"Bomberman.hpp"

Bomberman::Bomberman()// : _scene(new Menu(Vector3f(0, 0, 6000), Vector3f(0, 0, 0)))
{
}

Bomberman::~Bomberman()
{
  //delete this->_scene;
}

void		Bomberman::initialize()
{
  this->window_.create();
  this->_ctrl.initialize();
  /*
  this->camera_.initialize(1024, 768, this->_scene->getPoscam(), this->_scene->getTarget(), 0);
  this->objects_.push_back(new Cube(Vector3f(-400, 0, -400), Vector3f(400, -5, 400), "./ressource/toto.tga"));
  this->objects_.push_back(new Cube(Vector3f(-250, 50, 150), Vector3f(-200, 0, 100), "./ressource/carreaux.tga"));
  this->objects_.push_back(new Cube(Vector3f(-150, 50, 150), Vector3f(-100, 0, 100), "./ressource/carreaux.tga"));
  this->objects_.push_back(new Cube(Vector3f(-50, 50, 150), Vector3f(0, 0, 100), "./ressource/carreaux.tga"));
  this->objects_.push_back(new Cube(Vector3f(50, 50, 150), Vector3f(100, 0, 100), "./ressource/carreaux.tga"));
  this->objects_.push_back(new Cube(Vector3f(150, 50, 150), Vector3f(200, 0, 100), "./ressource/carreaux.tga"));
  this->objects_.push_back(new Cube(Vector3f(-400, 300, 0), Vector3f(400, -300, 1), "./ressource/background.png"));
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->initialize();
  */
  //this->_scene->initialize("./ressource/Bomberman.fbx");
}

void		Bomberman::update()
{
  bool		tmp = false;
  /*
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->update(gameClock_, input_);
  //this->_scene->update(gameClock_);
  camera_.update(gameClock_, input_);
  */
  this->gameClock_.update();
  tmp = this->_ctrl.update(this->gameClock_, this->input_);
  if (tmp || this->input_.isKeyDown(gdl::Keys::Escape) == true)
    this->window_.close();
}

void		Bomberman::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0, 0, 0, 1.0f);
  glClearDepth(1.0f);
  this->_ctrl.draw();
  /*
  this->camera_.draw();
  //this->_scene->draw();
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->draw();
  */
}

void		Bomberman::unload()
{
}
