/*
** Bomberman.h for  in /home/lund/Projets/bomberpony
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon May 13 17:01:39 2013 florian dewulf
** Last update Wed May 15 00:25:53 2013 florian dewulf
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
  QUIT
};

typedef int	MenuType;

enum eMode {
  EASY,
  MEDIUM,
  HARD
};

#endif
