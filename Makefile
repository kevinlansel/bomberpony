##
## Makefile for  in /home/lund/Projets/bomberpony
## 
## Made by florian dewulf
## Login   <dewulf_f@epitech.net>
## 
## Started on  Sun May  5 14:07:28 2013 florian dewulf
## Last update Tue May 21 15:59:17 2013 guillaume duez
##

NAME=		Bomberman

SRC=		APlayer.cpp		\
		AObject.cpp		\
		Bombe.cpp		\
		Bomberman.cpp		\
		Camera.cpp		\
		Collision.cpp		\
		Controller.cpp		\
		File.cpp		\
		Forme.cpp		\
		main.cpp		\
		Menu.cpp		\
		Musique.cpp		\
		Obstacle.cpp		\
		Scene.cpp		\
		Map.cpp			\
		Sound.cpp		\
		Vector3f.cpp

OBJ=		$(SRC:.cpp=.o)

CC=		g++

GDL=		-I libgdl_gl-2012.4/include/ -L libgdl_gl-2012.4/lib/ -Wl,--rpath=./libgdl_gl-2012.4/lib/ -lgdl_gl -lGL -lGLU

CXXFLAGS=	-W -Wall -Wextra $(GDL) -lsfml-audio -lsfml-system

all:		$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(GDL) -ggdb3 -lsfml-audio -lsfml-system

$(NAME):	all

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
