/*
** proto.c for wolf3d in /home/delaun_m/cours_minilibx
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Tue Dec 16 10:27:32 2014 Marc DELAUNAY
** Last update Sun Dec 21 13:36:40 2014 Marc DELAUNAY
*/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "struct.h"

void	set(t_system *sys)
{
  sys->mvt.x0 = 2;
  sys->mvt.y0 = 2;
  sys->mvt.rad = -3 * M_PI / 4;
}

int	wolf(int len, int high)
{
  t_system	sys;

  if ((sys.mlx = mlx_init()) == NULL)
      return (0);
  sys.win = mlx_new_window(sys.mlx, len, high, "wolf3d");
  sys.image.image = mlx_new_image(sys.mlx, len, high);
  sys.image.data = mlx_get_data_addr(sys.image.image, &(sys.image.bpp),
				     &(sys.image.sizeline), &(sys.image.endian));
  sys.image.background = mlx_new_image(sys.mlx, len, high);
  sys.image.ground = mlx_get_data_addr(sys.image.image, &(sys.image.bpq),
				       &(sys.image.sizeline), &(sys.image.endian));
  set(&sys);
  map(&sys);
  movement(&sys, 0);
  mlx_expose_hook(sys.win, &func_expose, &sys);
  mlx_hook(sys.win, KeyPress, KeyPressMask, &func_key_pressed, &sys);
  mlx_loop(sys.mlx);
  return (0);
}

int	main()
{
  wolf(W_LEN, W_HIGH);
  return (0);
}
