/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:19:27 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/23 21:25:02 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "libcolor.h"
# define POINTER_MOTION (1L<<6)
# define MOTION_NOTIFY 6
# define WIDTH 640
# define HEIGHT 480
# define BLACK 0x000000

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

typedef struct	s_cel
{
	t_cplx	z;
	char	is_out;
}				t_cel;

typedef struct	s_env
{
	char	*av;
	void	*mlx;
	void	*win;
	t_img	img;
	t_scn	scn;
	int		iter;
	char	done;
	t_cplx	c;
	t_cplx	z;
	void	(*function)(struct s_env *);
	double	julia_x;
	double	julia_y;
	int		i;
}				t_env;

void			init_fractol(t_env *env);
void			img_clear(void *mlx, t_img *img);
void			img_putpixel(t_env *env, t_pnt pnt, int color);
void			img_move(t_env *env, int mx, int my);
void			draw_mandelbrot(t_env *env);
void			draw_julia(t_env *env);
void			draw_ship(t_env *env);
void			error(void);
int				key_hook(int keycode, t_env *env);
int				expose_hook(t_env *env);
int				loop_hook(t_env *env);
void			fractol_exit(t_env **env);

#endif
