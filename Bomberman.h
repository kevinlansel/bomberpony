/*
** Bomberman.h for  in /home/lund/Projets/bomberpony
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon May 13 17:01:39 2013 florian dewulf
** Last update Tue May 14 15:18:13 2013 florian dewulf
*/

#ifndef		BOMBERMAN_H__
# define	BOMBERMAN_H__

enum {
  NOTHING,
  MENU,
  BATTLE,
  GAME,
  SCORE,
  OPTION,
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
