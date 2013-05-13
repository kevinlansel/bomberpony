//
// Player.cpp for bomberman in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Thu May  9 11:21:55 2013 gery baudry
// Last update Mon May 13 13:48:30 2013 gery baudry
//

Player::Player(bool player) : _winx(10), _winy(10), _joueur(player), _bomb(1)
{
}

Player::~Player()
{
}

void		Player::move(gdl::Input &input)
{
  if (this->_joueur)
    move_player_one(input);
  else
    move_player_two(input);
}

void		Player::move_player_one(gdl::Input &input)
{
  if (input.isKeyDown(gdl::Keys::Right) == true)
    this->_winx += 1;
  if (input.isKeyDown(gdl::Keys::Left) == true)
    this->_winx -= 1;
  if (input.isKeyDown(gdl::Keys::Up) == true)
    this->_winy -= 1;
  if (input.isKeyDown(gdl::Keys::Down) == true)
    this->_winy += 1;
  if (input.isKeyDown(gdl::Keys::RControl) == true && this->_bomb != 0)
    //pose la bombinette && décrémente le nbr de bombe
    //appel a la fonction affichage
    //fonction timer pour explosion + accrémentation une fois la bombe explosé
}

void		Player::move_player_two(gdl::Input &input)
{
  if (input.isKeyDown(gdl::Keys::D) == true)
    this->_winx += 1;
  if (input.isKeyDown(gdl::Keys::Q) == true)
    this->_winx -= 1;
  if (input.isKeyDown(gdl::Keys::Z) == true)
    this->_winy -= 1;
  if (input.isKeyDown(gdl::Keys::S) == true)
    this->_winy += 1;
  if (input.isKeyDown(gdl::Keys::LControl) == true && this->_bomb != 0)
    //pose la bombinette && décrémente le nombre de bombe
    //appel a la fonction affichage
    //fonction timer pour explosion + accrémentation une fois la bombe explosé
}

void		Player::check_item(Item &item)
{
  //Verification des item pris par le joueur
}

int		Player::getWinx() const
{
  return (this->_winx);
}

int		Player::getWiny() const
{
  return (this->_winy);
}

void		Player::getBomb() const
{
  return (this->_bomb);
}

void		Player::setWinx(int x)
{
  this->_winx = x;
}

void		Player::setWiny(int y)
{
  this->_winy = y;
}

void		Player::setBomb(int bomb)
{
  this->_bomb = bomb;
}
