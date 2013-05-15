//
// Controller.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 15:52:40 2013 florian dewulf
// Last update Thu May 16 00:52:03 2013 florian dewulf
//

#include	"Controller.hpp"

Controller::Controller() : _scene(NULL), _sound(true), _map_choice(true), _map_option("15"), _screen(MENU)
{
  int		menu[] = {5, GAME, OPTION, SCORE, QUIT};
  int		score[] = {2, MENU};
  int		option[] = {5, SOUND, MAP_TYPE, MAP_OPTION, MENU};
  int		game[] = {4, ONE, TWO, MENU};

  this->_map_menu[MENU] = std::vector<int>(menu, menu + sizeof(menu) / sizeof(int));
  this->_map_menu[GAME] = std::vector<int>(game, game + sizeof(game) / sizeof(int));
  this->_map_menu[SCORE] = std::vector<int>(score, score + sizeof(score) / sizeof(int));
  this->_map_menu[OPTION] = std::vector<int>(option, option + sizeof(option) / sizeof(int));
}

Controller::~Controller()
{
  delete this->_scene;
}

void		Controller::initialize()
{
  this->_scene = new Menu(Vector3f(0, 0, 5000), Vector3f(0, 0, 0), MENU, this->_map_menu[MENU]);
  this->_scene->initialize("./ressource/background.png", Vector3f(40, 52, 0), Vector3f(40, 52 - ((this->_map_menu[MENU][0] - 2) * 65), 0));
  this->_scene->setColor(255, 255, 255);
  this->setText();
}

void		Controller::Majmap()
{
  File		f;

  if (f.getStatemap())
    this->_map = f.ls();
}

void		Controller::Majscore()
{
}

bool		Controller::update(gdl::GameClock &clock, gdl::Input &input)
{
  MenuType	tmp;

  tmp = this->_scene->update(clock, input);
  if (dynamic_cast<Menu *>(this->_scene))
    this->_screen = reinterpret_cast<Menu *>(this->_scene)->getChoice();//Dans le constructeur faire une map de ptr sur func
  if (tmp == QUIT)
    return (true);
  else if (tmp != NOTHING)// != sound, etc
    this->changeScene(this->_scene->getPoscam(), this->_scene->getTarget(), this->_screen, this->_map_menu[this->_screen]);
  return false;
}

void		Controller::draw()
{
  this->_scene->draw();
}

void		Controller::changeScene(const Vector3f &pos, const Vector3f &target, MenuType type, std::vector<int> &limit)
{
  if (this->_scene)//pas pour tout
    delete this->_scene;
  if (type == MENU || type == GAME || type == SCORE || type == OPTION)
    {
      this->_scene = new Menu(Vector3f(0, 0, 5000), Vector3f(0, 0, 0), type, limit);
      this->_scene->initialize("./ressource/background.png", Vector3f(40, 52, 0), Vector3f(40, 52 - ((limit[0] - 2) * 65), 0));
      this->_scene->setColor(255, 255, 255);
      this->setText();
    }
  else if (type == BATTLE)//plutot == J1 ou J2 ou loadgame
    ;//game
  //else if ()//si map_type => passe le booléen à != valeur | si map_option => get
  //;//modif value
  else
    ;//load écran de victoire ou fail
  this->_screen = type;
}

void		Controller::setText()
{
  std::vector<int>	tab = this->_map_menu[this->_screen];
  std::string		str = "";

  for (std::vector<int>::iterator it = tab.begin() ; it != tab.end() ; ++it)
    {
      if (it == tab.begin())
	continue;
      switch (*it)
	{
	case MENU:
	  str += "Return\n";
	  break;
	case GAME:
	  str += "Play\n";
	  break;
	case SCORE:
	  str += "Ladder\n";
	  break;
	case OPTION:
	  str += "Options\n";
	  break;
	case SOUND:
	  str += "Sound:";
	  if (this->_sound)
	    str += "On\n";
	  else
	    str += "Off\n";
	  break;
	case MAP_TYPE:
	  str += "Map:";
	  if (this->_map_choice)
	    str += "Rand\n";
	  else
	    str += "Def\n";
	  break;
	case MAP_OPTION:
	  str += this->_map_option + "\n";
	  break;
	case ONE:
	  str += "1J\n";
	  break;
	case TWO:
	  str += "2J\n";
	  break;
	case QUIT:
	  str += "Exit\n";
	  break;
	default:
	  break;
	}
    }
  this->_scene->setTxt(str, 500, 200);
}
