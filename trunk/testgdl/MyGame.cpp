#include	"MyGame.hpp"

void MyGame::initialize(void)
{
  window_.create();
  camera_.initialize();
  this->objects_.push_back(new Cube(Vector3f(-2100, 0, -2100), Vector3f(2100, -1, 2100), "./toto.tga"));
  int		a = -2100;
  int		b = -1800;
  int		c = -2100;
  int		d = -1800;
  while (a < 2100)
    {
      this->objects_.push_back(new Cube(Vector3f(-2100, 300, a), Vector3f(-1800, 0, b), "./carreaux.tga"));
      while (c < 2100)
	{
	  this->objects_.push_back(new Cube(Vector3f(c, 300, -2100), Vector3f(d, 0, -1800), "./carreaux.tga"));
	  c += 300;
	  d += 300;
	}
      a += 300;
      b += 300;
    }
  a = 2100;
  b = 1800;
  c = 2100;
  d = 1800;
  while (a > -2100)
    {
      this->objects_.push_back(new Cube(Vector3f(2100, 300, a), Vector3f(1800, 0, b), "./carreaux.tga"));
      while (c > -2100)
	{
	  this->objects_.push_back(new Cube(Vector3f(c, 300, 2100), Vector3f(d, 0, 1800), "./carreaux.tga"));
	  c -= 300;
	  d -= 300;
	}
      a -= 300;
      b -= 300;
    }
  this->model = new Bombe();
  this->model->initialize();
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
  this->model->update(gameClock_, input_);
}

void MyGame::draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->draw();
  this->model->draw();
}

void MyGame::unload(void)
{
}
