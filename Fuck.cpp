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

      for (std::list<Bombe *>::iterator it2 = list_tmp.begin(); it2 != list_tmp.end() ; ++it2)
	{
	  list.push_back("bomb:" + /*it->getJoueur()*/);//mettre en param les coordonnées de la bombe comme pour le joueur
	}

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
      tab[y][xtmp] = '1';
  for (; ytmp < y + 2 ; ++ytmp)
    if (ytmp != y && ytmp >= 0 && ytmp < size && tab[ytmp][x] != '2')
      tab[ytmp][x] = '1';
}

std::vector<std::string>	Bot::BombMapGenerator(const std::list<Bombe *> &list, unsigned int size)
{
  int				x;
  int				y;
  std::string			model;
  std::vector<std::string>	tab;

  for (unsigned int i = 0 ; i < size ; ++i)
    model += '0';
  for (unsigned int i = 0 ; i < size ; ++i)
    tab.push_back(std::string(model));
  for (std::list<Bombe *>::const_iterator it = list.begin() ; it != list.end() ; ++it)
    {
      x = (int)(((*it)->getCoord().x + (size * 150)) / 300);
      y = (int)(((*it)->getCoord().z + (size * 150)) / 300);
      tab[y][x] = '2';
      this->putExplosion(tab, x, y, size);
    }
  return tab;
}
