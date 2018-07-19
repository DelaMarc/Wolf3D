/*
** struct.h for  in /home/delaun_m/cours_minilibx
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Tue Nov 25 18:16:03 2014 Marc DELAUNAY
** Last update Sun Jan  4 00:08:25 2015 Marc DELAUNAY
*/

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <X11/X.h>

#define	W_LEN	800
#define	W_HIGH	800
#define	P	0.5
#define	D	0.3
#define	A	param->mvt.rad
#define	TAB	param->field
#define	LOST	sys->calc.lost
#define	SVX	sys->calc.svx
#define	SVY	sys->calc.svy
#define	X_VIEW	(int)sys->calc.x_view
#define	Y_VIEW	(int)sys->calc.y_view

typedef struct	s_color
{
  int	color_n;
  int	color_s;
  int	color_e;
  int	color_o;
}	t_color;

typedef struct	s_mvt
{
  float		rad;
  float		x0;
  float		y0;
  char		map;
}	t_mvt;

typedef struct	s_calc
{
  float	x_view;
  float	y_view;
  float	k_prev;
  float	k_next;
  float	view_prev;
  float	view_next;
  float	Vx;
  float	Vy;
  float	k;
  float	svk;
  int	svx;
  int	svy;
  int	lost;
  int	x;
}	t_calc;

typedef struct	s_image
{
  void	*image;
  void	*background;
  char	*ground;
  char	*data;
  int	bpp;
  int	bpq;
  int	pos;
  int	sizeline;
  int	endian;
  int	y;
}	t_image;

typedef struct	s_system
{
  char		map;
  char		*field[18];
  int		wall2;
  void		*mlx;
  void		*win;
  int		sizeline;
  t_mvt		mvt;
  t_calc	calc;
  t_image	image;
}	t_system;

#endif /* !SYSTEM_H_ */

void	map(t_system*);
void	put_pixel_to_image(int, int, int, t_system*);
int	func_expose(t_system*);
int	func_key_pressed(int, t_system*);
