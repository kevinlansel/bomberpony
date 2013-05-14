void			Controller::save_game_player(std::list<APlayer> aplayer)
{
  std::list<string>		list;
  std::stringstream		ss;
  Vector3f			pos;
  int				joueur;
  int				bomb;
  std::string			name;
  bool				alive;

  for (std::list<APlayer>::iterator it = aplayer.begin(); it != aplayer.end(); ++it)
    {
      pos = it->getPos();
      joueur = it->getJoueur();
      bomb = it->getBomb();
      name = it->getName();
      alive = it->getAlive();
    }
  list.push_front("TYPE:APLAYER");
  ss.str("pos:");
  ss << "x" << pos.x << "y" << pos.y << "z" << pos.z;
  list.push_back(ss.str());
  ss.clear();
  ss.str("joueur:");
  ss << joueur;
  list.push_back(ss.str());
  ss.clear();
  ss.str("bomb:");
  ss << bomb;
  list.push_back(ss.str());
  ss.clear();
  list.push_back("name:" + name);
  ss.str("alive:");
  ss << alive;
  list.push_back(ss.str());
  ss.clear();
}

void			Controller::save_game_obstacle(std::list<Obstacle> obs)
{
  typeObs			type;
  Vector3f			vec;
  std::stringstream		ss;
  std::list<string>		list;

  for (std::list<Obstacle>::iterator it = obs.begin(); it != obs.end(); ++it)
    {
      type = it->getType();
      vec = it->getVec();
    }
  list.push_front("TYPE:OBSTACLE");
  ss.str("type:");
  ss << type;
  list.push_back(ss.str());
  ss.clear();
  ss.str("Pos:")
  ss << "x" << pos.x << "y" << pos.y << "z" << pos.z;
  list.push_back(ss.str());
  ss.clear();
}
