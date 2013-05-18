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
