//
// Controller.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 15:52:40 2013 florian dewulf
// Last update Wed May 15 12:55:42 2013 florian dewulf
//

#include	"Controller.hpp"

Controller::Controller() : _scene(NULL), _sound(true), _map_choice(true), _map_option(""), _screen(MENU)  //le 5 envoyé en param du menu à modif
{
  int		menu[] = {5, GAME, OPTION, SCORE, QUIT};
  int		score[] = {2, MENU};
  int		option[] = {5, SOUND_ON, MAP_TYPE_RAND, MAP_OPTION, MENU};
  int		game[] = {4, ONE, TWO, MENU};

  //std::cout << (int)(score + sizeof(score) / sizeof(int)) << std::endl;
  this->_map_menu[MENU] = std::vector<int>(menu, menu + sizeof(menu) / sizeof(int));
  this->_map_menu[GAME] = std::vector<int>(game, game + sizeof(game) / sizeof(int));//{1, QUIT};
  this->_map_menu[SCORE] = std::vector<int>(score, score + sizeof(score) / sizeof(int));//{1, QUIT};
  this->_map_menu[OPTION] = std::vector<int>(option, option + sizeof(option) / sizeof(int));//{1, QUIT};
}

Controller::~Controller()
{
  delete this->_scene;
}

void		Controller::initialize()
{
  this->_scene = new Menu(Vector3f(0, 0, 5000), Vector3f(0, 0, 0), MENU, this->_map_menu[MENU]);
  this->_scene->initialize("./ressource/background.png", Vector3f(40, 52, 0), Vector3f(40, -158, 0));
  this->_scene->setColor(255, 255, 255);
  //  this->_scene->setTxt("  Play\nOption\nLadder\n  Exit\n", 500, 200);
  // envoyer la liste des enums correspondants aux menus.
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
    this->_screen = reinterpret_cast<Menu *>(this->_scene)->getChoice();
  if (tmp == QUIT)
    return (true);
  else if (tmp != NOTHING)
    this->changeScene(this->_scene->getPoscam(), this->_scene->getTarget(), this->_screen, this->_map_menu[this->_screen]);//à corriger pour la limite
  return false;
}

void		Controller::draw()
{
  this->_scene->draw();
}

void		Controller::changeScene(const Vector3f &pos, const Vector3f &target, MenuType type, std::vector<int> &limit)
{
  std::cout << type << std::endl;
  if (this->_scene)
    delete this->_scene;
  std::cout << type << std::endl;
  if (type == MENU || type == GAME || type == SCORE || type == OPTION)
    {
      std::cout << type << std::endl;
      this->_scene = new Menu(Vector3f(0, 0, 5000), Vector3f(0, 0, 0), type, limit);
      this->_scene->initialize("./ressource/background.png", Vector3f(40, 52, 0), Vector3f(40, -158, 0));
      this->_scene->setColor(255, 255, 255);
      //this->_scene->setTxt("  Play\nOption\nLadder\n  Exit\n", 500, 200);
    }
  else if (type == BATTLE)
    ;//game
  else
    ;//load écran de victoire ou fail
  this->_screen = type;
}
