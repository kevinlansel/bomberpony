//
// Forme.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 19:52:14 2013 florian dewulf
// Last update Sun May  5 17:57:45 2013 florian dewulf
//

#include	"Forme.hpp"

/* Triangle */

/*
void Triangle::initialize(void)
{
}

void Triangle::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
}

void Triangle::draw(void)
{
  glBegin(GL_TRIANGLES);
  glColor3f(1.0f, 0.50f, 0.75f);
  glVertex3f(0.0f, 150.0f, 0.0f);
  glVertex3f(-150.0f, 0.0f, 0.0f);
  glVertex3f(150.0f, 00.0f, 0.0f);
  glEnd();
}
*/

/* Rectangle */

/*
void Rectangle::initialize(void)
{
}

void Rectangle::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
}

void Rectangle::draw(void)
{
  glBegin(GL_QUADS);
  glColor3f(1.0f, 0.50f, 0.75f);
  glVertex3f(-150.0f, 100.0f, 0.0f);
  glVertex3f(-150.0f, -100.0f, 0.0f);
  glVertex3f(150.0f, -100.0f, 0.0f);
  glVertex3f(150.0f, 100.0f, 0.0f);
  glEnd();
}
*/

/* Cube */

Cube::Cube(const Vector3f &ori, const Vector3f &oppo, const std::string &texture) : _origin(ori), _opposite(oppo)
{
  if (texture != "")
    {
      this->_stateTexture = true;
      this->_texture = gdl::Image::load(texture);
    }
  else
    this->_stateTexture = false;
}

Cube::~Cube()
{
}

void Cube::initialize(void)
{
}

void Cube::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  /*
  this->rotation_.x = ((int)rotation_.x - 1) % 360;
  this->rotation_.y = ((int)rotation_.y - 1) % 360;
  this->rotation_.z = ((int)rotation_.z - 1) % 360;
  */
}

void Cube::draw(void)
{
  if (this->_stateTexture)
    this->_texture.bind();
  glPushMatrix();
  glLoadIdentity();
  /*
    glRotatef(this->rotation_.x, 1.0f, 0.0f, 0.0f);
    glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);
    glRotatef(this->rotation_.z, 0.0f, 0.0f, 1.0f);
  */
  glBegin(GL_QUADS);

  if (this->_stateTexture)
    {
      glTexCoord2f(0.0, 0.0);
      glVertex3f(this->_origin.x, this->_origin.y, this->_origin.z);
      glTexCoord2f(1.0, 0.0);
      glVertex3f(this->_opposite.x, this->_origin.y, this->_origin.z);
      glTexCoord2f(1.0, 1.0);
      glVertex3f(this->_opposite.x, this->_opposite.y, this->_origin.z);
      glTexCoord2f(0.0, 1.0);
      glVertex3f(this->_origin.x, this->_opposite.y, this->_origin.z);
    }
  else
    {
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex3f(this->_origin.x, this->_origin.y, this->_origin.z);
      glVertex3f(this->_opposite.x, this->_origin.y, this->_origin.z);
      glVertex3f(this->_opposite.x, this->_opposite.y, this->_origin.z);
      glVertex3f(this->_origin.x, this->_opposite.y, this->_origin.z);
    }

  if (this->_stateTexture)
    {
      glTexCoord2f(0.0, 0.0);
      glVertex3f(this->_origin.x, this->_origin.y, this->_origin.z);
      glTexCoord2f(1.0, 0.0);
      glVertex3f(this->_opposite.x, this->_origin.y, this->_origin.z);
      glTexCoord2f(1.0, 1.0);
      glVertex3f(this->_opposite.x, this->_origin.y, this->_opposite.z);
      glTexCoord2f(0.0, 1.0);
      glVertex3f(this->_origin.x, this->_origin.y, this->_opposite.z);
    }
  else
    {
      glColor3f(0.0f, 1.0f, 1.0f);
      glVertex3f(this->_origin.x, this->_origin.y, this->_origin.z);
      glVertex3f(this->_opposite.x, this->_origin.y, this->_origin.z);
      glVertex3f(this->_opposite.x, this->_origin.y, this->_opposite.z);
      glVertex3f(this->_origin.x, this->_origin.y, this->_opposite.z);
    }

  if (this->_stateTexture)
    {
      glTexCoord2f(0.0, 0.0);
      glVertex3f(this->_origin.x, this->_origin.y, this->_opposite.z);
      glTexCoord2f(1.0, 0.0);
      glVertex3f(this->_opposite.x, this->_origin.y, this->_opposite.z);
      glTexCoord2f(1.0, 1.0);
      glVertex3f(this->_opposite.x, this->_opposite.y, this->_opposite.z);
      glTexCoord2f(0.0, 1.0);
      glVertex3f(this->_origin.x, this->_opposite.y, this->_opposite.z);
    }
  else
    {
      glColor3f(1.0f, 0.0f, 1.0f);
      glVertex3f(this->_origin.x, this->_origin.y, this->_opposite.z);
      glVertex3f(this->_opposite.x, this->_origin.y, this->_opposite.z);
      glVertex3f(this->_opposite.x, this->_opposite.y, this->_opposite.z);
      glVertex3f(this->_origin.x, this->_opposite.y, this->_opposite.z);
    }

  if (this->_stateTexture)
    {
      glTexCoord2f(0.0, 0.0);
      glVertex3f(this->_origin.x, this->_opposite.y, this->_origin.z);
      glTexCoord2f(1.0, 0.0);
      glVertex3f(this->_opposite.x, this->_opposite.y, this->_origin.z);
      glTexCoord2f(1.0, 1.0);
      glVertex3f(this->_opposite.x, this->_opposite.y, this->_opposite.z);
      glTexCoord2f(0.0, 1.0);
      glVertex3f(this->_origin.x, this->_opposite.y, this->_opposite.z);
    }
  else
    {
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex3f(this->_origin.x, this->_opposite.y, this->_origin.z);
      glVertex3f(this->_opposite.x, this->_opposite.y, this->_origin.z);
      glVertex3f(this->_opposite.x, this->_opposite.y, this->_opposite.z);
      glVertex3f(this->_origin.x, this->_opposite.y, this->_opposite.z);
    }

  if (this->_stateTexture)
    {
      glTexCoord2f(0.0, 0.0);
      glVertex3f(this->_origin.x, this->_origin.y, this->_origin.z);
      glTexCoord2f(1.0, 0.0);
      glVertex3f(this->_origin.x, this->_origin.y, this->_opposite.z);
      glTexCoord2f(1.0, 1.0);
      glVertex3f(this->_origin.x, this->_opposite.y, this->_opposite.z);
      glTexCoord2f(0.0, 1.0);
      glVertex3f(this->_origin.x, this->_opposite.y, this->_origin.z);
    }
  else
    {
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex3f(this->_origin.x, this->_origin.y, this->_origin.z);
      glVertex3f(this->_origin.x, this->_origin.y, this->_opposite.z);
      glVertex3f(this->_origin.x, this->_opposite.y, this->_opposite.z);
      glVertex3f(this->_origin.x, this->_opposite.y, this->_origin.z);
    }

  if (this->_stateTexture)
    {
      glTexCoord2f(0.0, 0.0);
      glVertex3f(this->_opposite.x, this->_origin.y, this->_origin.z);
      glTexCoord2f(1.0, 0.0);
      glVertex3f(this->_opposite.x, this->_origin.y, this->_opposite.z);
      glTexCoord2f(1.0, 1.0);
      glVertex3f(this->_opposite.x, this->_opposite.y, this->_opposite.z);
      glTexCoord2f(0.0, 1.0);
      glVertex3f(this->_opposite.x, this->_opposite.y, this->_origin.z);
    }
  else
    {
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex3f(this->_opposite.x, this->_origin.y, this->_origin.z);
      glVertex3f(this->_opposite.x, this->_origin.y, this->_opposite.z);
      glVertex3f(this->_opposite.x, this->_opposite.y, this->_opposite.z);
      glVertex3f(this->_opposite.x, this->_opposite.y, this->_origin.z);
    }
  glEnd();
  glPopMatrix();
}

  /* Pyramide */

  Pyramide::Pyramide(const Vector3f &v1, const Vector3f &v2, const Vector3f &v3, const Vector3f &sommet) : _v1(v1), _v2(v2), _v3(v3), _sommet(sommet)
  {
  }

  Pyramide::~Pyramide()
    {
    }

  void Pyramide::initialize(void)
  {
  }

  void Pyramide::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    this->rotation_.x = ((int)rotation_.x + 1) % 360;
    this->rotation_.y = ((int)rotation_.y + 1) % 360;
    this->rotation_.z = ((int)rotation_.z + 1) % 360;
  }

  void Pyramide::draw(void)
  {
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -900.0f);
    glRotatef(this->rotation_.x, 1.0f, 0.0f, 0.0f);
    glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);
    glRotatef(this->rotation_.z, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);

    /*base*/
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(this->_v1.x, this->_v1.y, this->_v1.z);
    glVertex3f(this->_v2.x, this->_v2.y, this->_v2.z);
    glVertex3f(this->_v3.x, this->_v3.y, this->_v3.z);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(this->_sommet.x, this->_sommet.y, this->_sommet.z);
    glVertex3f(this->_v1.x, this->_v1.y, this->_v1.z);
    glVertex3f(this->_v2.x, this->_v2.y, this->_v2.z);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(this->_sommet.x, this->_sommet.y, this->_sommet.z);
    glVertex3f(this->_v1.x, this->_v1.y, this->_v1.z);
    glVertex3f(this->_v3.x, this->_v3.y, this->_v3.z);

    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(this->_sommet.x, this->_sommet.y, this->_sommet.z);
    glVertex3f(this->_v2.x, this->_v2.y, this->_v2.z);
    glVertex3f(this->_v3.x, this->_v3.y, this->_v3.z);

    glEnd();
    glPopMatrix();
  }
