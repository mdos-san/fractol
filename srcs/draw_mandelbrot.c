/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 21:53:11 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/16 11:27:09 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_env *env)
{
	double	tmp;
	t_scn	scn;
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	i = 0;
	scn = env->scn;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			if (*(unsigned int *)(env->img.data + env->img.bpp * x + env->img.sl * y) == 0x000000)
			{
				while (i < env->iter && env->z.r * env->z.r + env->z.i * env->z.i < 4)
				{
					env->c.r = scn.a.x;
					env->c.i = scn.a.y;
					tmp = env->z.r;
					env->z.r = env->z.r * env->z.r - env->z.i * env->z.i - env->c.r;
					env->z.i = 2 * env->z.i * tmp + env->c.i;
					++i;
				}
				if (env->z.r * env->z.r + env->z.i * env->z.i < 4)
					img_putpixel(env, (t_pnt){x, y}, 0x000000);
				else
					img_putpixel(env, (t_pnt){x, y}, color_convert(color_get((i * 12) % 256, (i * 24) % 256, (i * 42) % 256, 0)));
				i = 0;
				env->z.r = 0;
				env->z.i = 0;
			}
			x++;
			scn.a.x += scn.step_x;
		}
		x = 0;
		scn.a.x = env->scn.a.x;
		y++;
		scn.a.y += scn.step_y;
	}
}
