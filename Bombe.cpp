//
// Bombe.cpp for Bombe in /home/haz3/projet/bomberpony
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Mon May 13 10:55:07 2013 Maxime Wojciak
// Last update Mon May 13 13:39:42 2013 Maxime Wojciak
//

#include	<ctime>
#include	"Bombe.hpp"

Bombe::Bombe() {

}

/*
** Class Input
** On pose la bombe.
*/

void		Bombe::DropBombe(gdl::Input & input) {
  if (input.isKeyDown(gdl::Keys::Space) == true)
  {
    std::cout << "je pose une bombe" << std::endl << "Wait 5s" std::endl;
    sleep(5000);
    std::cout << "La Bombe Explose" << std::endl;
    std::cout << "Je détruis la bombe" << std::endl;
  }
}

Bombe::~Bombe() {

}
