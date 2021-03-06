//
// Controller.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 15:52:40 2013 florian dewulf
// Last update Mon May 27 09:18:52 2013 florian dewulf
//

#include	"Controller.hpp"

Controller::Controller() : _scene(NULL), _sound(true), _map_choice(true), _map_option("15"), _screen(MENU), _ia(0), _offset(0), _musique("./ressource/contact.wav")
{
  int		menu[] = {5, GAME, OPTION, SCORE, QUIT};
  int		score[] = {2, MENU};
  int		option[] = {6, SOUND, MAP_TYPE, MAP_OPTION, IA, MENU};
  int		game[] = {5, ONE, TWO, LOAD, MENU};

  this->_map_menu[MENU] = std::vector<int>(menu, menu + sizeof(menu) / sizeof(int));
  this->_map_menu[GAME] = std::vector<int>(game, game + sizeof(game) / sizeof(int));
  this->_map_menu[SCORE] = std::vector<int>(score, score + sizeof(score) / sizeof(int));
  this->_map_menu[OPTION] = std::vector<int>(option, option + sizeof(option) / sizeof(int));

  this->_ptr_func[MENU] = &Controller::putMenu;
  this->_ptr_func[GAME] = &Controller::putMenu;
  this->_ptr_func[SCORE] = &Controller::putMenu;
  this->_ptr_func[OPTION] = &Controller::putMenu;
  this->_ptr_func[ONE] = &Controller::launchInput;
  this->_ptr_func[TWO] = &Controller::launchInput;
  this->_ptr_func[MAP_OPTION] = &Controller::returnOption;
  this->_ptr_func[MAP_TYPE] = &Controller::returnOption;
  this->_ptr_func[SOUND] = &Controller::changeSound;
  this->_ptr_func[MAP_TYPE] = &Controller::changeTypeMap;
  this->_ptr_func[IA] = &Controller::changeIA;
  this->_ptr_func[LOAD] = &Controller::returnGame;
  this->_ptr_func[INC_OPTION] = &Controller::incOption;
  this->_ptr_func[DEC_OPTION] = &Controller::decOption;
  this->_ptr_func[END_INPUT] = &Controller::launchGame;
}

Controller::~Controller()
{
  delete this->_scene;
}

void		Controller::initialize()
{
  this->Majmap();
  this->_scene = new Menu(Vector3f(0, 0, 5000), Vector3f(0, 0, 0), MENU, this->_map_menu[MENU]);
  this->_scene->initialize("./ressource/background.png", Vector3f(40, 52, 0), Vector3f(40, 52 - ((this->_map_menu[MENU][0] - 2) * 65), 0));
  this->_scene->setColor(255, 255, 255);
  this->setText();
  this->_musique.PlayMusique();
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

  tmp = this->_scene->update(clock, input, this->_sound);
  if (dynamic_cast<Menu *>(this->_scene) && tmp != INC_OPTION && tmp != DEC_OPTION)
    this->_screen = reinterpret_cast<Menu *>(this->_scene)->getChoice();
  else if (dynamic_cast<Menu *>(this->_scene) && (tmp == INC_OPTION || tmp == DEC_OPTION))
    this->_screen = tmp;
  if (tmp == QUIT)
    return (true);
  else if (tmp != NOTHING)
    this->changeScene();
  return false;
}

void		Controller::draw()
{
  this->_scene->draw();
}

void		Controller::changeScene()
{
  this->_screen = (this->*(this->_ptr_func[this->_screen]))();
  this->setText();
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
	case LOAD:
	  str += "Load\n";
	  break;
	case IA:
	  str += "IA:" + ((this->_ia == 0) ? std::string("Easy\n") : ((this->_ia == 1) ? std::string("Medium\n") : std::string("Hard\n")));
	  break;
	default:
	  break;
	}
    }
  this->_scene->setTxt(str, 500, 200);
}

MenuType	Controller::changeSound()
{
  this->_sound = !this->_sound;
  if (this->_sound)
    this->_musique.PlayMusique();
  else
    this->_musique.StopMusique();
  return OPTION;
}

MenuType	Controller::changeTypeMap()
{
  if (this->_map.size() > 0)
    {
      this->_map_choice = !this->_map_choice;
      if (!this->_map_choice)
	this->changeMap();
      else
	this->_map_option = "15";
    }
  return OPTION;
}

MenuType	Controller::changeIA()
{
  this->_ia++;
  if (this->_ia == HARD + 1)
    this->_ia = EASY;
  return OPTION;
}

MenuType	Controller::returnGame()
{
  return GAME;
}

MenuType	Controller::returnOption()
{
  return OPTION;
}

void		Controller::changeMap()
{
  if (this->_map.size() == 0)
    {
      this->_offset = 0;
      this->_map_choice = true;
      this->_map_option = "15";
    }
  else
    {
      if (this->_offset >= this->_map.size())
	this->_offset = 0;
      std::list<std::string>::iterator it = this->_map.begin();
      for (unsigned int i = 0 ; i < this->_offset && it != this->_map.end() ; ++i, ++it);
      this->_map_option = *it;
    }
}

MenuType	Controller::incOption()
{
  int			nb;
  std::stringstream	ss;

  if (this->_map_choice)
    {
      nb = Utils::StringToInt(this->_map_option);
      nb++;
      ss.str("");
      ss << nb;
      this->_map_option = ss.str();
    }
  else
    {
      this->_offset++;
      this->changeMap();
    }
  return OPTION;
}

MenuType	Controller::decOption()
{
  int			nb;
  std::stringstream	ss;

  if (this->_map_choice && (nb = Utils::StringToInt(this->_map_option)) > 15)
    {
      nb--;
      ss.str("");
      ss << nb;
      this->_map_option = ss.str();
    }
  else if (this->_map_choice == false)
    {
      this->_offset--;
      this->changeMap();
    }
  return OPTION;
}

MenuType	Controller::launchInput()
{
  delete this->_scene;
  this->_scene = new InputBox(this->_screen);
  this->_scene->initialize("", Vector3f(0, 0, 0), Vector3f(0, 0, 0));
  return (this->_screen);
}

MenuType	Controller::putMenu()
{
  delete this->_scene;
  this->_scene = new Menu(Vector3f(0, 0, 5000), Vector3f(0, 0, 0), this->_screen, this->_map_menu[this->_screen]);
  this->_scene->initialize("./ressource/background.png", Vector3f(40, 52, 0), Vector3f(40, 52 - ((this->_map_menu[this->_screen][0] - 2) * 65), 0));
  this->_scene->setColor(255, 255, 255);
  return this->_screen;
}

MenuType	Controller::launchGame()
{
  //delete this->_scene;
  //this->_scene = new Gameplay();
}
