/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:19:27 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/06 17:24:40 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# define WIDTH 600
# define HEIGHT 600

typedef struct	s_img
{
	void	*img;
	char	*data;
	int		bpp;
	int		sl;
	int		endian;
}				t_img;

typedef struct	s_pnt
{
	double	x;
	double	y;
}				t_pnt;

typedef struct	s_scn
{
	t_pnt	a;
	t_pnt	b;
	double	step_x;
	double	step_y;
}				t_scn;

typedef struct	s_cplx
{
	double	r;
	double	i;
}				t_cplx;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_scn	scn;
	int		iter;
	char	first_draw;
}				t_env;

void		img_clear(void *mlx, t_img *img);
void		img_putpixel(t_env *env, t_pnt pnt, int color);
void		draw_mandelbrot(t_env *env, t_scn scn, int iter);

#endif
