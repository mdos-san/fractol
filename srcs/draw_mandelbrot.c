/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 21:53:11 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/14 16:44:07 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculate_fractal(t_env *env, t_scn *scn, int *x, int *y)
{
	double	tmp;

	while (env->i < env->iter && env->z.r * env->z.r + env->z.i * env->z.i < 4)
	{
		env->c.r = scn->a.x;
		env->c.i = scn->a.y;
		tmp = env->z.r;
		env->z.r = env->z.r * env->z.r - env->z.i * env->z.i - env->c.r;
		env->z.i = 2 * env->z.i * tmp + env->c.i;
		++env->i;
	}
	(env->i == env->iter) ?
	img_putpixel(env, (t_pnt){*x, *y}, 0x000000) :
	img_putpixel(env, (t_pnt){*x, *y},
	color_convert(color_get((env->i * 12) % 256,
			(env->i * 24) % 256, (env->i * 42) % 256, 0)));
	env->i = 0;
	env->z.r = 0;
	env->z.i = 0;
	++*x;
	scn->a.x += scn->step_x;
}

void		draw_mandelbrot(t_env *env)
{
	t_scn	scn;
	int		x;
	int		y;

	x = 0;
	y = 0;
	scn = env->scn;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
			if (*(unsigned int *)(env->img.data + env->img.bpp * x +
											env->img.sl * y) == 0x000000)
				calculate_fractal(env, &scn, &x, &y);
		x = 0;
		scn.a.x = env->scn.a.x;
		y++;
		scn.a.y += scn.step_y;
	}
}
