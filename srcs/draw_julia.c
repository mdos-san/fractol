/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:11:11 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/14 16:44:06 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculate_fractal(t_env *env, t_scn *scn, int *x, int *y)
{
	double	tmp;

	env->z.r = scn->a.x;
	env->z.i = scn->a.y;
	env->c.r = env->julia_x;
	env->c.i = env->julia_y;
	while (env->i < env->iter && env->z.r *
			env->z.r + env->z.i * env->z.i < 4)
	{
		tmp = env->z.r;
		env->z.r =
			env->z.r * env->z.r - env->z.i * env->z.i + env->c.r;
		env->z.i = 2 * env->z.i * tmp + env->c.i;
		++env->i;
	}
	if (env->z.r * env->z.r + env->z.i * env->z.i < 4)
		img_putpixel(env, (t_pnt){*x, *y}, 0x000000);
	else
		img_putpixel(env, (t_pnt){*x, *y}, color_convert(
					color_get((env->i * 12) % 256,
						(env->i * 24) % 256, (env->i * 42) % 256, 0)));
	env->i = 0;
	++*x;
	scn->a.x += scn->step_x;
}

void		draw_julia(t_env *env)
{
	t_scn	scn;
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	i = 0;
	scn = env->scn;
	env->i = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
			calculate_fractal(env, &scn, &x, &y);
		x = 0;
		scn.a.x = env->scn.a.x;
		++y;
		scn.a.y += scn.step_y;
	}
}
