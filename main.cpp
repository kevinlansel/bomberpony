//
// main.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May  4 19:15:17 2013 florian dewulf
// Last update Tue May 21 16:56:07 2013 florian dewulf
//

#include	<cstdlib>
#include	<ctime>
#include	"Bomberman.hpp"

int		main()
{
  Bomberman	bomber;

  srand(time(NULL));
  bomber.run();
  return (0);
}
