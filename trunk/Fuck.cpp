void			save_game(std::list<APlayer *> aplayer, std::list<Obstacle *> obs)//LISTE DE BONUS A AVOIR EN +
{
  std::list<string>		list;
  Vector3f			pos;

  for (std::list<APlayer *>::iterator it = aplayer.begin(); it != aplayer.end(); ++it)
    {
      std::list<Bombe *>	list_tmp;

      list_tmp = (*it)->getBomb();

      list.push_front("TYPE:APLAYER");
      list.push_back("pos:" + Utils::expandString("x", (*it)->getPos().x) + Utils::expandString("y", (*it)->getPos().y) + Utils::expandString("z", (*it)->getPos().z));
      list.push_back("joueur:", (*it)->getJoueur());
      //dynamic cast, si bot, alors put le mode de difficulté, sinon le name
      list.push_back("name:" + (*it)->getName());

      /*for (std::list<Bombe *>::iterator it2 = list_tmp.begin(); it2 != list_tmp.end() ; ++it2)
	{
	  list.push_back("bomb:" + /*it->getJoueur()*/);//mettre en param les coordonnées de la bombe comme pour le joueur
  /*}			LISTE DE BOMBE A PUT AUTRE PART*/

      list.push_back(Utils::expandString("alive:", (*it)->getAlive()));
    }
  for (std::list<Obstacle *>::iterator it = obs.begin() ; it != obs.end() ; ++it)
    {
      list.push_front("TYPE:OBSTACLE");
      list.push_front(Utils::expandString("type:", (*it)->type));
      list.push_front("pos:" + Utils::expandString("x:", (*it)->getVec().x) + Utils::expandString("y:", (*it)->getVec().y) + Utils::expandString("z:", (*it)->getVec().z));
    }
  return (list);
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
