/*
** Bomberman.h for  in /home/lund/Projets/bomberpony
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon May 13 17:01:39 2013 florian dewulf
** Last update Mon May 20 13:57:36 2013 florian dewulf
*/

#ifndef		BOMBERMAN_H__
# define	BOMBERMAN_H__

enum {
  NOTHING = 0,
  MENU,
  BATTLE,
  GAME,
  SCORE,
  OPTION,
  SOUND,
  MAP_TYPE,
  MAP_OPTION,
  ONE,
  TWO,
  VICTORY,
  GAMEOVER,
  IA,
  LOAD,
  QUIT
};

typedef int	MenuType;

enum eMode {
  EASY,
  MEDIUM,
  HARD
};

#endif
