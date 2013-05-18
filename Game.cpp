//
// Game.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Fri May 17 19:43:28 2013 florian dewulf
// Last update Sat May 18 02:35:03 2013 florian dewulf
//

#include	"Game.hpp"

Game::Game(bool sound, bool map_choice, bool nb_j) : Scene(Vector3f(0, 0, 0), Vector3f(0, 0, 0)), _error(false), _nb_j(nb_j), _sound(sound), _map_choice(map_choice)
{
}

//Game::Game(list string &) = load

Game::~Game()
{
}

void		Game::initialize(const std::string &map_type)
{
  Map				map;
  std::list<std::string>	list_str;

  if (this->_map_choice)
    this->_error = map.initialize(Utils::StringToInt(map_type), list_str, this->_nb_j);//list_str en référence
  else
    this->_error = map.initialize(map_type, list_str, this->_nb_j);//list_str en référence
  if (this->_error)
    return;
  this->setPoscam(Vector3f(0, list_str.size() * 300 / 0.8, list_str.size() * 150));//300 is the size of a block. 150 = 300 / 2.
  for (std::list<std::string>::iterator it = list_str.begin(), unsigned int i = 0 ; it != list_str.end() ; ++it, ++i)
    for (unsigned int j = 0 ; j < it->size() ; ++j)
      {
	if ((*it)[j] == 0)
	  this->obs.push_back(new Obstacle(/* param obstacle destructible*/));//Vector3f(j * 300 - (list_str.size() * 300) / 2, 0, i * 300 - (list_str.size() * 300) / 2, 0)
	else if ((*it)[j] == 1)
	  this->obs.push_back(new Obstacle(/* param obstacle indestructible*/));//Vector3f(j * 300 - (list_str.size() * 300) / 2, 0, i * 300 - (list_str.size() * 300) / 2, 0)
	else
	  this->newPlayer(list_str.size(), i, j, (*it));
      }
}

MenuType	Game::update(gdl::GameClock &clock, gdl::Input &input)
{
  for (std::list<Obstacle *>::iterator it = this->_obs.begin() ; it != this->_obs.end() ; ++it)
    (*it)->update(clock, input, this->_players, this->_bonus);
  for (std::list<APlayer *>::iterator it = this->_players.begin() ; it != this->_players.end() ; ++it)
    (*it)->update(clock, input, this->_obs);
}

void		Game::draw()
{
  for (std::list<Obstacle *>::iterator it = this->_obs.begin() ; it != this->_obs.end() ; ++it)
    (*it)->draw();
  for (std::list<APlayer *>::iterator it = this->_players.begin() ; it != this->_players.end() ; ++it)
    (*it)->draw();
}

void		Game::newPlayer(unsigned int size_list, unsigned int x, unsigned int y)
{
  if (this->_players.size() == 0)
    this->_players.push_back(new Player(/*param j1*/));//Vector3f(y * 300 - (size_list * 300) / 2, 0, x * 300 - (size_list * 300) / 2, 0)
  else if (this->_players.size() == 1)
    this->_players.push_back(new Player(/*param j2*/));//Vector3f(y * 300 - (size_list * 300) / 2, 0, x * 300 - (size_list * 300) / 2, 0)
  else
    this->_players.push_back(new Bot(/*param*/));//Vector3f(y * 300 - (size_list * 300) / 2, 0, x * 300 - (size_list * 300) / 2, 0)
}
