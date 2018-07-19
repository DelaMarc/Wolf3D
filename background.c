/*
** background.c for wolf3d in /home/delaun_m/clone_army/MUL_2014_wolf3d
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Sun Dec 21 11:04:29 2014 Marc DELAUNAY
** Last update Sun Dec 21 13:51:25 2014 Marc DELAUNAY
*/

#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "struct.h"

void	map(t_system *sys)
{
  int	i = 0;
  sys->field[0] = "111111111111111111";
  sys->field[1] = "101000000001000001";
  sys->field[2] = "100010010101000001";
  sys->field[3] = "111111110101000001";
  sys->field[4] = "100000000001110001";
  sys->field[5] = "111111100000100001";
  sys->field[6] = "101000101010001001";
  sys->field[7] = "101110000010000001";
  sys->field[8] = "101011010010010001";
  sys->field[9] = "100010000000000001";
  sys->field[10] = "111111111111111111";
  sys->field[11] = NULL;
  while (sys->field[i])
    {
      printf("%s\n", sys->field[i]);
      i++;
    }
}

void	sky(t_system *sys, int i)
{
  if (i < W_LEN * W_HIGH * 2)
    {
      if (i % 27777 == 0 || i % 37000 == 0)
	{
	  sys->image.data[i] = 255;
	  sys->image.data[i + 1] = 255;
	  sys->image.data[i + 2] = 255;
	}
    }
}

void	background(t_system *sys)
{
  int	i;

  i = 0;
  while (i < W_LEN * W_HIGH * 2)
    {
      sys->image.data[i] = 0;
      sys->image.data[i + 1] = 0;
      sys->image.data[i + 2] = 0;
      sky(sys, i);
      i += 4;
    }
  while (i < W_LEN * W_HIGH * 4)
    {
      sys->image.data[i] = 0;
      sys->image.data[i + 1] = 41;
      sys->image.data[i + 2] = 88;
      i += 4;
    }
}
