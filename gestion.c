/*
** gestion.c for wolf3d in /home/delaun_m/clone_army/MUL_2014_wolf3d
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Sun Dec 21 11:13:36 2014 Marc DELAUNAY
** Last update Sun Dec 21 11:14:36 2014 Marc DELAUNAY
*/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "struct.h"

void	put_pixel_to_image(int color, int x, int y, t_system *param)
{
  int	pos;

  pos = y * param->image.sizeline + x * 4;
  param->image.ground[pos] = color % 256;
  param->image.ground[pos + 1] = (color >> 8) % 256;
  param->image.ground[pos + 2] = (color >> 16) % 256;
  param->image.ground[pos + 3] = 0;
}

int	func_expose(t_system *param)
{
  mlx_put_image_to_window(param->mlx, param->win, param->image.image, 0, 0);
  return (0);
}

int	func_key_pressed(int keycode, t_system *param)
{
  if (keycode == 65307)
    {
      mlx_destroy_window(param->mlx, param->win);
      exit(0);
    }
  movement(param, keycode);
  func_expose(param);
  return (0);
}
