//
// Forme.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 19:52:14 2013 florian dewulf
// Last update Tue May  7 21:50:24 2013 florian dewulf
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

Rectangle::Rectangle()
{
}

Rectangle::~Rectangle()
{
}

/*void Rectangle::initialize(void)
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
}*/

/*
** Draw a rectangle of the color given
** ori = first point, end = point at the opposite, the three float are the RGB
*/
void		Rectangle::draw_rect(const Vector3f &ori, const Vector3f &end, float Rcolor, float Vcolor, float Bcolor)
{
  glBegin(GL_QUADS);
  glColor3f(Rcolor, Vcolor, Bcolor);
  glVertex3f(ori.x, ori.y, ori.z);
  glVertex3f(end.x, ori.y, end.z);
  glVertex3f(end.x, end.y, end.z);
  glVertex3f(ori.x, end.y, end.z);
  glEnd();
}

/*
** Draw a rectangle of the color given [=> Rectangle à plat]
** ori = first point, end = point at the opposite, the three float are the RGB
*/
void		Rectangle::draw_plan(const Vector3f &ori, const Vector3f &end, float Rcolor, float Vcolor, float Bcolor)
{
  glBegin(GL_QUADS);
  glColor3f(Rcolor, Vcolor, Bcolor);
  glVertex3f(ori.x, ori.y, ori.z);
  glVertex3f(end.x, ori.y, ori.z);
  glVertex3f(end.x, end.y, end.z);
  glVertex3f(ori.x, ori.y, end.z);
  glEnd();
}

/*
** Draw a rectangle with the texture given
** ori = first point, end = point at the opposite, img = the texture
*/
void		Rectangle::draw_rect(const Vector3f &ori, const Vector3f &end, gdl::Image &img)
{
  img.bind();
  glEnable(GL_TEXTURE_2D);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0, 0.0);
  glVertex3f(ori.x, ori.y, ori.z);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(end.x, ori.y, end.z);
  glTexCoord2f(1.0, 1.0);
  glVertex3f(end.x, end.y, end.z);
  glTexCoord2f(0.0, 1.0);
  glVertex3f(ori.x, end.y, end.z);
  glEnd();
  glDisable(GL_TEXTURE_2D);
}

/*
** Draw a rectangle with the texture given [=> Rectangle à plat]
** ori = first point, end = point at the opposite, img = the texture
*/
void		Rectangle::draw_plan(const Vector3f &ori, const Vector3f &end, gdl::Image &img)
{
  img.bind();
  glEnable(GL_TEXTURE_2D);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0, 0.0);
  glVertex3f(ori.x, ori.y, ori.z);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(end.x, ori.y, ori.z);
  glTexCoord2f(1.0, 1.0);
  glVertex3f(end.x, ori.y, end.z);
  glTexCoord2f(0.0, 1.0);
  glVertex3f(ori.x, ori.y, end.z);
  glEnd();
  glDisable(GL_TEXTURE_2D);
}

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
  glPushMatrix();
  glLoadIdentity();
  /*
    glRotatef(this->rotation_.x, 1.0f, 0.0f, 0.0f);
    glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);
    glRotatef(this->rotation_.z, 0.0f, 0.0f, 1.0f);
  */

  // Les 4 faces non horizontales
  Rectangle::draw_rect(Vector3f(this->_origin.x, this->_origin.y, this->_origin.z), Vector3f(this->_opposite.x, this->_opposite.y, this->_origin.z), this->_texture);
  Rectangle::draw_rect(Vector3f(this->_origin.x, this->_origin.y, this->_opposite.z), Vector3f(this->_opposite.x, this->_opposite.y, this->_opposite.z), this->_texture);
  Rectangle::draw_rect(Vector3f(this->_origin.x, this->_origin.y, this->_origin.z), Vector3f(this->_origin.x, this->_opposite.y, this->_opposite.z), this->_texture);
  Rectangle::draw_rect(Vector3f(this->_opposite.x, this->_origin.y, this->_origin.z), Vector3f(this->_opposite.x, this->_opposite.y, this->_opposite.z), this->_texture);

  // La face du dessus
  Rectangle::draw_plan(Vector3f(this->_origin.x, this->_origin.y, this->_origin.z), Vector3f(this->_opposite.x, this->_origin.y, this->_opposite.z), this->_texture);
  // La face du dessous. Qui est blanche car sinon il y a un bug de couleur du cube. Et comme on voit pas le dessous...
  Rectangle::draw_plan(Vector3f(this->_origin.x, this->_opposite.y, this->_origin.z), Vector3f(this->_opposite.x, this->_opposite.y, this->_opposite.z), this->_texture);
  //Rectangle::draw_plan(Vector3f(this->_origin.x, this->_opposite.y, this->_origin.z), Vector3f(this->_opposite.x, this->_opposite.y, this->_opposite.z), 1.0, 1.0, 1.0);

  glPopMatrix();
}

/* Pyramide */

Pyramide::Pyramide(const Vector3f &v1, const Vector3f &v2, const Vector3f &v3, const Vector3f &sommet) : _v1(v1), _v2(v2), _v3(v3), _sommet(sommet)
{
}

Pyramide::~Pyramide()
{
}

void	Pyramide::initialize(void)
{
}

void	Pyramide::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  this->rotation_.x = ((int)rotation_.x + 1) % 360;
  this->rotation_.y = ((int)rotation_.y + 1) % 360;
  this->rotation_.z = ((int)rotation_.z + 1) % 360;
}

void	Pyramide::draw(void)
{
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(0.0f, 200.0f, 0.0f);
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
