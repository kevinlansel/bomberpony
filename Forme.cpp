//
// Forme.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 19:52:14 2013 florian dewulf
// Last update Mon May 13 14:37:29 2013 florian dewulf
//

#include	"Forme.hpp"

/* Triangle */

Triangle::Triangle(const Vector3f &pt1, const Vector3f &pt2, const Vector3f &pt3, const Vector3f &color) : _pt1(pt1), _pt2(pt2), _pt3(pt3), _color(color), _rotation(0), _translation(0, 0, 0)
{
}

void Triangle::initialize()
{
}

void Triangle::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  (void)gameClock;
  (void)input;
  this->_rotation = ((int)this->_rotation - 1) % 360;
}

void Triangle::draw()
{
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(this->_translation.x, this->_translation.y, this->_translation.z);
  glRotatef(this->_rotation, 1.0, 0.0, 0.0);
  glBegin(GL_TRIANGLES);
  glColor3f(this->_color.x, this->_color.y, this->_color.z);
  glVertex3f(/*translation.x - */this->_pt1.x, /*translation.y - */this->_pt1.y, /*translation.z - */this->_pt1.z);
  glVertex3f(/*translation.x - */this->_pt2.x, /*translation.y - */this->_pt2.y, /*translation.z - */this->_pt2.z);
  glVertex3f(/*translation.x - */this->_pt3.x, /*translation.y - */this->_pt3.y, /*translation.z - */this->_pt3.z);
  glEnd();
  glPopMatrix();
}

void		Triangle::setTranslation(const Vector3f &vec)
{
  this->_translation.x = vec.x;
  this->_translation.y = vec.y;
  this->_translation.z = vec.z;
}

Vector3f	Triangle::getTranslation() const
{
  return this->_translation;
}

/* Rectangle */

Rectangle::Rectangle()
{
}

Rectangle::~Rectangle()
{
}

/*
void		Rectangle::initialize(void)
{
}

void		Rectangle::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
}

void		Rectangle::draw(void)
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
  this->_rotation.x = ((int)_rotation.x - 1) % 360;
  this->_rotation.y = ((int)_rotation.y - 1) % 360;
  this->_rotation.z = ((int)_rotation.z - 1) % 360;
  */
}

void Cube::draw(void)
{
  glPushMatrix();
  glLoadIdentity();
  /*
    glRotatef(this->_rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(this->_rotation.y, 0.0f, 1.0f, 0.0f);
    glRotatef(this->_rotation.z, 0.0f, 0.0f, 1.0f);
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
  this->_rotation.x = ((int)_rotation.x + 1) % 360;
  this->_rotation.y = ((int)_rotation.y + 1) % 360;
  this->_rotation.z = ((int)_rotation.z + 1) % 360;
}

void	Pyramide::draw(void)
{
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(0.0f, 200.0f, 0.0f);
  glRotatef(this->_rotation.x, 1.0f, 0.0f, 0.0f);
  glRotatef(this->_rotation.y, 0.0f, 1.0f, 0.0f);
  glRotatef(this->_rotation.z, 0.0f, 0.0f, 1.0f);
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