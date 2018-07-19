##
## Makefile for  in /home/delaun_m/cours_minilibx
## 
## Made by Marc DELAUNAY
## Login   <delaun_m@epitech.net>
## 
## Started on  Thu Dec  4 12:51:55 2014 Marc DELAUNAY
## Last update Sun Dec 21 13:55:43 2014 Marc DELAUNAY
##

NAME	= wolf3d

SRC	= main.c \
	  wall.c \
	  background.c \
	  gestion.c \
	  moves.c 

OBJ	= $(SRC:.c=.o)

CC	= cc -g

RM	= rm -f

all:	$(NAME)

$(NAME): $(OBJ)
	 $(CC) $(OBJ) -L. -lm -lmlx -lXext -lX11 -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
