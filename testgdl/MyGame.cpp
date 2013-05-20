#include	"MyGame.hpp"

void MyGame::initialize(void)
{
  window_.create();
  camera_.initialize();
  this->objects_.push_back(new Cube(Vector3f(-2000, 0, -2000), Vector3f(2000, -1, 2000), "./toto.tga"));
  this->objects_.push_back(new Cube(Vector3f(-500, 300, -500), Vector3f(-200, 0, -200), "./carreaux.tga"));
  this->model = gdl::Model::load("./marvin.fbx");
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->initialize();
}

void MyGame::update(void)
{
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->update();
  camera_.update(gameClock_, input_);
  this->model.play("Take 001");
  this->model.update(gameClock_);
}

void MyGame::draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->draw();
  this->model.draw();
}

void MyGame::unload(void)
{
}
