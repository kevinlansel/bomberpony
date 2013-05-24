//
// Bot.cpp for Bomberman in /home/seth/C++/bomberpony
// 
// Made by kevin lansel
// Login   <lansel_k@epitech.net>
// 
// Started on  Mon May 13 17:07:06 2013 kevin lansel
// Last update Fri May 24 15:24:05 2013 kevin lansel
//

#include	<sstream>
#include	<cstdlib>
#include	"Bot.hpp"

static std::string	giveName()
{
  static int		id = 1;
  std::stringstream	ss;

  ss.str("Bot-");
  ss << id;
  id += 1;
  return (ss.str());
}

Bot::Bot(unsigned int x, unsigned int y, unsigned int size, eMode m) : Player(-1, giveName()), _x(x), _y(y), _size(size), _mode(m)
{
}

Bot::~Bot()
{

}

void		Bot::setMode(eMode mode)
{
  this->_mode = mode;
}

void		Bot::setX(unsigned int x)
{
  this->_x = x;
}

void		Bot::setY(unsigned int y)
{
  this->_y = y;
}

void		Bot::setSize(unisgned int size)
{
  this->_size = size;
}

eMode		Bot::getMode() const
{
  return (this->_mode);
}

unsigned int	Bot::getX() const
{
  return (this->_x);
}

unsigned int	Bot::getY() const
{
  return (this->_y);
}

unsigned int	Bot::getSize() const
{
  return (this->_size);
}

Vector3f      getPos() const
{
  return (this->_posActu);
}

Vector3f      getDest() const
{
  return (this->_destination);
}

void		Bot::update(gld::GameClock &clock, gdl::Input &in, const std::list<Obstacle *> &obs, const std::list<Bombe *> &bombe)
{
  (void)in;
  if (this->_mode == EASY)
    easy(obs, bombe);
  else if (this->_mode == MEDIUM)
    medium(obs, bombe);
  else
    hard(obs, bombe);
}

void		Bot::easy(const std::list<Obstacle *> &obs, const std::list<Bombe *> &bombe)
{
  unsigned int		rd;

  rd = rand() % 2;
  if (rd == 1)
    rdoff(bombe);
  else
    rddef(obs, bombe);
}

void		Bot::medium(const std::list<Obstacle *> &obs, const std::list<Bombe *> &bombe)
{
  std::vector<std::string>	mapmv;

  mapmv = this->BombMapGenerator(bombe);
  if (secure(mapv))
    rdoff(bombe);
  else
    defensif(obs, bombe, mapv);
}

void		Bot::hard(const std::list<Obstacle *> &obs, const std::list<Bombe *> &bombe)
{
  std::vector<std::string>	mapmv;

  mapmv = this->BombMapGenerator(bombe);
  if (secure(mapv))
    offensif();
  else
    deffensif(obs, bombe, mapv);
}

void		Bot::rdoff(const std::list<Bombe *> &bombe)
{
  unsigned int		rd;

  rd = rand() % 7;
  if (rd == 0)
    bombe.push_back(new Bombe(Utils::CoordToVec(this->_x, this->_size), 0, Utils::CoordToVec(this->_y, this->_size)));
}

void		Bot::rddef(const std::list<Obstacle *> &obs, const std::list<Bombe *> &bombe)
{
  unsigned int		rd;

  for (unsigned int i = 0; i < 4 ; i++)
    {
      rd = rand() % 4;
      switch (rd)
	{
	case 0: /* left */
	  if (trymove(bombe, obs, this->_x - 1, this->_y))
	    this->_destination.x -= 300;
	  break;
	case 1: /* right */
	  if (trymove(bombe, obs, this->_x + 1, this->_y))
	    this->_destination.x += 300;
	  break;
	case 2: /* up */
	  if (trymove(bombe, obs, this->_x, this->_y + 1))
	    this->_destination.z -= 300;
	  break;
	case 3: /* down */
	  if (trymove(bombe, obs, this->_x, this->_y - 1))
	    this->_destination.z += 300;
	  break;
	default:
	  break;
	}
    }
}

void		Bot::offensif(const std::list<Bombe> &bombe)
{

}

void		Bot::defensif(const std::list<Obstacle *> &obs, const std::list<Bombe *> &bombe, const std::vector<std::string> &mapbombe)
{
  std::vector<std::string>		mappond;
  eDir					dir;

  mappond = this->PondDir(mapbombe);
  dir = this->giveMove(obs, mappond);
  this->MoveBot(dir);
}

bool		Bot::secure(const std::vector<std::string> &mapmv)
{
  if (mapmv[this->_y][this->_x] == '0')
    return (true);
  else
    return (false);
}

bool		Bot::trymove(const std::list<Bombe *> &bombe, const std::list<Obstacle *> &obs, unsigned int x, unsigned int y)
{
  if (x == 0 || x == this->_size || y == 0 || y == this->_size)
    return (false);
  for (std::list<Obstacle *>::iterator it = obs.begin() ; it != obs.end() ; ++it)
    {
      if (x == Utils::VecToCoord((*it)->getPosition().x, this->_size) && y == Utils::VecToCoord((*it)->getPosition().z, this->_size))
	return (false);
    }
  for (std::list<Bombe *>::iterator it = bombe.begin() ; it != bombe.end() ; ++it)
    {
      if (x == Utils::VecToCoord((*it)->getPosition().x, this->_size) && y == Utils::VecToCoord((*it)->getPosition().z, this->_size))
	return (false);
    }
  return (true);
}

unsigned int	Bot::giveUp(unsigned int x, unsigned int y, std::vector<std::string> mapmv)
{
  int		pond;
  std::string	save;

  save = mapv[y + 1];
  pond = Utils::StringToInt(save.substr(x, 1));
  return (pond);
}

unsigned int	Bot::giveDown(unsigned int x, unsigned int y, std::vector<std::string> mapmv)
{
  int		pond;
  std::string	save;

  save = mapv[y - 1];
  pond = Utils::StringToInt(save.substr(x, 1));
  return (pond);
}

unsigned int	Bot::giveRight(unsigned int x, unsigned int y, std::vector<std::string> mapmv)
{
  int		pond;
  std::string	save;

  save = mapv[y];
  pond = Utils::StringToInt(save.substr(x + 1, 1));
  return (pond);
}

unsigned int	Bot::giveLeft(unsigned int x, unsigned int y, std::vector<std::string> mapmv)
{
  int		pond;
  std::string	save;

  save = mapv[y];
  pond = Utils::StringToInt(save.substr(x - 1, 1));
  return (pond);
}

static eDir	where(std::Map<eDir, int> pond)
{
  int		save;
  eDir		dir;

  save = 0;
  dir = DEFAULT;
  for (std::Map<eDir, int>::iterator it = pond.begin() ; it != pond.end() ; ++it)
    {
      if (*it > save)
	save = *it;
    }
  for (std::Map<eDir, int>::iterator it = pond.begin() ; it != pond.end() ; ++it)
    {
      if (*it == save)
	dir = it->first;
    }
  return (dir);
}

eDir			Bot::giveMove(const std::list<Obstacle> &obs, std::vector<std::string> &mapmv)
{
  int			i;
  eDir			trys;
  Vector3f		vec((this->_x * 300 - (this->_size * 300) / 2), 0, (this->y * 300 - (this->_size) / 2));
  std::Map<eDir, int>	pond;

  i = 0;
  trys = DEFAULT;
  pond[UP] = giveUp(this->_x, this->_y, mapv);
  pond[DOWN] = giveDown(this->_x, this->_y, mapv);
  pond[RIGHT] = giveRight(this->_x, this->_y, mapv);
  pond[LEFT] = giveLeft(this->_x, this->_y, mapv);
  while (i < 4)
    {
      trys = where(pond);
      for (std::list<Obstacle>::iterator it = obs.begin() ; it != obs.end() ; ++it)
	{
	  int		x;
	  int		y;

	  x = Utils::VecToCoord(it->getPosition().x, this->_size);
	  y = Utils::VecToCoord(it->getPosition().z, this->_size);
	  if (this->_x == x && this->_y == y)
	    mapmv[y][x] = '0';
	  else
	    return (trys);
	}
      i++;
    }
  return (trys);
}

void				Bot::putExplosion(std::vector<std::string> &tab, const int &x, const int &y, const unsigned int &size)
{
  int				xtmp = x - 2;
  int				xtmp = y - 2;

  for (; xtmp < x + 2 ; ++xtmp)
    if (xtmp != x && xtmp >= 0 && xtmp < size && tab[y][xtmp] != '2')
      tab[y][xtmp] += 1;
  for (; ytmp < y + 2 ; ++ytmp)
    if (ytmp != y && ytmp >= 0 && ytmp < size && tab[ytmp][x] != '2')
      tab[ytmp][x] += 1;
}

std::vector<std::string>	Bot::BombMapGenerator(const std::list<Bombe *> &list)
{
  int				x;
  int				y;
  std::string			model;
  std::vector<std::string>	tab;

  for (unsigned int i = 0 ; i < this->_size ; ++i)
    model += '0';
  for (unsigned int i = 0 ; i < this->_size ; ++i)
    tab.push_back(std::string(model));
  for (std::list<Bombe *>::const_iterator it = list.begin() ; it != list.end() ; ++it)
    {
      x = Utils::VecToCoord((*it)->getCoord().x, this->_size);
      y = Utils::VecToCoord((*it)->getCoord().z, this->_size);
      tab[y][x] = '*';
      this->putExplosion(tab, x, y, this->_size);
    }
  return tab;
}

void				Bot::PondCase(const std::vector<std::string> &map, int x, int y)
{
  if (!(x < 0 || x > map.size() || y < 0 || y > map.size()))
    map[y][x] += 1;
}

bool				Bot::checkCase(const std::vector<std::string> &mapBomb, const int x, const int y)
{
  if ((!(x < 0 || x > mapBomb.size() || y < 0 || y > mapBomb.size()) && mapBomb[y][x] != '0') || (x < 0 || x > mapBomb.size() || y < 0 || y > mapBomb.size()))
    return true;
  return false;
}

bool				Bot::checkLine(const std::vector<std::string> &mapBomb, int x[3], int y[3])
{
  if ((this->checkCase(mapBomb, x[0], y[0]) && this->checkCase(mapBomb, x[1], y[1])) || (this->checkCase(mapBomb, x[1], y[1]) && this->checkCase(mapBomb, x[2], y[2])))
    return false;
  return true;
}

void				Bot::PondLine(bool hor, bool vert, std::vector<std::string> &map)
{
  if (hor)
    {
      this->PondCase(map, this->x - 1, this->y);
      this->PondCase(map, this->x + 1, this->y);
    }
  else if (vert)
    {
      this->PondCase(map, this->x, this->y - 1);
      this->PondCase(map, this->x, this->y + 1);
}

std::vector<std::string>	Bot::PondDir(const std::vector<std::string> &mapBomb)
{
  bool				horizontal = true;
  bool				vertical = true;
  std::vector<std::string>	map(mapBomb);

  for (std::vector<std::string>::const_iterator it = mapBomb.begin ; it != mapBomb.end() ; ++it)
    for (unsigned int i = 0 ; i < it->size() ; ++i)
      (*it)[i] = '0';
  horizontal = this->checkLine(mapBomb, {this->x - 1, this->x, this->x + 1}, {this->y, this->y, this->y});
  vertical = this->checkLine(mapBomb, {this->x, this->x, this->x}, {this->y - 1, this->y, this->y + 1});
  if (mapBomb[this->y][this->x] == '0')
    map[this->y][this->x] = '1';
  this->pondLine(horizontal, vertical, map);
  this->checkCase(map, this->x, this->y);
  this->checkCase(map, this->x - 1, this->y);
  this->checkCase(map, this->x + 1, this->y);
  this->checkCase(map, this->x, this->y - 1);
  this->checkCase(map, this->x, this->y + 1);
  return map;
}

void				Bot::MoveBot(eDir direction)
{
  switch (direction)
    {
    case UP:
      this->_destination.z -= 300;
      break;
    case DOWN:
      this->_destination.z += 300;
      break;
    case LEFT:
      this->_destination.x -= 300;
      break;
    case RIGHT:
      this->_destination.x += 300;
      break;
    default:
      break;
    }
}
