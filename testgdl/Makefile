##
## Makefile for  in /home/lund/Projets/bomberpony
## 
## Made by florian dewulf
## Login   <dewulf_f@epitech.net>
## 
## Started on  Sun May  5 14:07:28 2013 florian dewulf
## Last update Tue May 21 17:26:16 2013 Maxime Wojciak
##

NAME=		Bomberman

SRC=		AObject.cpp		\
		MyGame.cpp		\
		Camera.cpp		\
		Forme.cpp		\
		main.cpp		\
		Vector3f.cpp		\
		Bombe.cpp

OBJ=		$(SRC:.cpp=.o)

CC=		g++

GDL=		-I libgdl_gl-2012.4/include/ -L libgdl_gl-2012.4/lib/ -Wl,--rpath=./libgdl_gl-2012.4/lib/ -lgdl_gl -lGL -lGLU

CXXFLAGS=	-W -Wall -Wextra $(GDL)

all:		$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(GDL) -ggdb3

$(NAME):	all

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
