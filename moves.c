/*
** movements.c for wolf3d in /home/delaun_m/cours_minilibx
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Tue Dec 16 10:49:35 2014 Marc DELAUNAY
** Last update Sun Dec 21 13:58:50 2014 Marc DELAUNAY
*/

#include <math.h>
#include "struct.h"

void	collision(t_system *param, int type)
{
  if (param->field[(int)param->mvt.x0][(int)param->mvt.y0] == '1')
    {
      if (type == 1)
	{
	  param->mvt.x0 += 0.1 * cos(A);
	  param->mvt.y0 += 0.1 * sin(A);
	}
      else
	{
	  param->mvt.x0 -= 0.1 * cos(A);
	  param->mvt.y0 -= 0.1 * sin(A);
	}
    }
}

void	teleport(t_system *param)
{
  if ((int)param->mvt.x0 == 1 && (int)param->mvt.y0 == 1)
    {
      param->mvt.x0 = 1;
      param->mvt.y0 = 16;
      A = 1 * M_PI / 4;
    }
}

void	movement(t_system *param, int keycode)
{
  background(param);
  if (keycode == 65361)
    A += M_PI / 36;
  if (keycode == 65363)
    A -= M_PI / 36;
  if (keycode == 65362)
   {
     param->mvt.x0 += 0.1 * cos(A);
     param->mvt.y0 += 0.1 * sin(A);
     collision(param, 0);
   }
  if (keycode == 65364)
   {
     param->mvt.x0 -= 0.1 * cos(A);
     param->mvt.y0 -= 0.1 * sin(A);
     collision(param, 1);
   }
  teleport(param);
  calc(param);
  mlx_put_image_to_window(param->mlx, param->win, param->image.image, 0, 0);
}
