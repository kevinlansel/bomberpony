#include	"MyGame.hpp"

void MyGame::initialize(void)
{
  this->_explosion = NULL;
  window_.create();
  camera_.initialize();
  this->objects_.push_back(new Cube(Vector3f(-2100, 0, -2100), Vector3f(2100, -1, 2100), "./textures/panda.png"));
  int		a = -2100;
  int		b = -1800;
  int		c = -2100;
  int		d = -1800;
  while (a < 2100)
    {
      this->objects_.push_back(new Cube(Vector3f(-2100, 300, a), Vector3f(-1800, 0, b), "./textures/box.png"));
      while (c < 2100)
	{
	  this->objects_.push_back(new Cube(Vector3f(c, 300, -2100), Vector3f(d, 0, -1800), "./textures/box.png"));
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
      this->objects_.push_back(new Cube(Vector3f(2100, 300, a), Vector3f(1800, 0, b), "./textures/box.png"));
      while (c > -2100)
	{
	  this->objects_.push_back(new Cube(Vector3f(c, 300, 2100), Vector3f(d, 0, 1800), "./textures/box.png"));
	  c -= 300;
	  d -= 300;
	}
      a -= 300;
      b -= 300;
    }
  this->_bombe = new Bombe(Vector3f(-200,0,-200));
  this->_bombe->initialize(this->gameClock_);
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->initialize();
}

void MyGame::update(void)
{
  this->gameClock_.update();
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->update();
  camera_.update(gameClock_, input_);
  if (this->_explosion == NULL && this->_bombe->update(gameClock_) == true)
  {
    this->_explosion = new Explosion(Vector3f(-200,0,-200), 2);
    this->_explosion->initialize();
    this->_explosion->update(this->gameClock_);
  }
  else if (this->_explosion)
    this->_explosion->update(gameClock_);
}

void MyGame::draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->draw();
  if (this->_explosion == NULL)
    this->_bombe->draw();
  else
    this->_explosion->draw();
}

void MyGame::unload(void)
{
}
