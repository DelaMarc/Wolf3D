/*
** tab.c for  in /home/delaun_m/cours_minilibx
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Fri Dec  5 17:12:43 2014 Marc DELAUNAY
** Last update Sun Dec 21 11:18:19 2014 Marc DELAUNAY
*/

#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "struct.h"

void	verif_wall(t_system *sys, int i)
{
  sys->calc.y_view = sys->mvt.y0 + (sys->calc.k * sys->calc.Vy);
  sys->calc.x_view = sys->mvt.x0 + (sys->calc.k * sys->calc.Vx);
  while (i < 1)
    {
      sys->calc.y_view = sys->mvt.y0 + (sys->calc.k * sys->calc.Vy);
      sys->calc.x_view = sys->mvt.x0 + (sys->calc.k * sys->calc.Vx);
      if (sys->calc.k > 0 && sys->field[(int)sys->calc.x_view]
	  [(int)sys->calc.y_view] == '1')
	  i = 1;
      sys->calc.k = sys->calc.k + 0.01;
    }
  sys->calc.svx = (int)(sys->mvt.x0 + ((sys->calc.k - 0.03) * sys->calc.Vx));
  sys->calc.svy = (int)(sys->mvt.y0 + ((sys->calc.k - 0.03) * sys->calc.Vy));
}

void		wall_display(t_system *sys, int i, float wall)
{
  while (i-- > W_HIGH / 2 - wall -1 && i > -1)
    {
      if (sys->calc.svy < sys->calc.y_view && SVX == X_VIEW)
	{
	  put_pixel_to_image(0x001B4F08, sys->calc.x, i, sys);
	  LOST = 0x001B4F08;
	}
      else if (sys->calc.svy > sys->calc.y_view && SVX == X_VIEW)
	{
	  put_pixel_to_image(0x00155732, sys->calc.x, i, sys);
	  LOST = 0x00155732;
	}
      else if (sys->calc.svx > sys->calc.x_view && SVY == Y_VIEW)
	{
	  put_pixel_to_image(0x0000561B, sys->calc.x, i, sys);
	  LOST = 0x000561B;
	}
      else if (sys->calc.svx < sys->calc.x_view && SVY == Y_VIEW)
	{
	  put_pixel_to_image(0x00386F48, sys->calc.x, i, sys);
	  LOST = 0x00386F48;
	}
      else
	put_pixel_to_image(LOST, sys->calc.x, i, sys);
    }
}

void		calc(t_system *sys)
{
  float		wall;
  int		i;

  sys->calc.x = 0;
  i = 0;
  while (sys->calc.x < W_LEN)
    {
      sys->calc.Vx = D * cos(sys->mvt.rad) - (P * (W_LEN / 2 - sys->calc.x) /
						W_LEN) * sin(sys->mvt.rad);
      sys->calc.Vy = D * sin(sys->mvt.rad) + (P * (W_LEN / 2 - sys->calc.x) /
						W_LEN) * cos(sys->mvt.rad);
      sys->calc.k = 0;
      i = 0;
      verif_wall(sys, i);
      wall = W_HIGH / (2 * sys->calc.k);
      if (wall > W_HIGH / 2)
	wall = W_HIGH / 2;
      i = W_HIGH / 2 + wall;
      put_pixel_to_image(0x00FFD700, sys->calc.x, i + 1, sys);
      put_pixel_to_image(0x00FFD700, sys->calc.x, i + 2, sys);
      wall_display(sys, i, wall);
      put_pixel_to_image(0x00FFD700, sys->calc.x, W_HIGH / 2 - wall -2, sys);
      put_pixel_to_image(0x00FFD700, sys->calc.x, W_HIGH / 2 - wall -3, sys);
      sys->calc.x += 1;
    }
}
