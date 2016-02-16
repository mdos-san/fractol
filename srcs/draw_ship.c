/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:46:13 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/16 09:25:10 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_ship(t_env *env, int nbr)
{
	t_cplx	c;
	t_cplx	z;
	double	tmp;
	t_scn	scn;
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	i = 0;
	z.r = 0;
	z.i = 0;
	scn = env->scn;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			if (*(unsigned int *)(env->img.data + env->img.bpp * x + env->img.sl * y) == 0x000000)
			{
				while (i < nbr && z.r * z.r + z.i * z.i < 4)
				{
					c.r = scn.a.x;
					c.i = scn.a.y;
					z.r = fabs(z.r);
					z.i = fabs(z.i);
					tmp = z.r;
					z.r = z.r * z.r - z.i * z.i - c.r;
					z.i = 2 * z.i * tmp + c.i;
					++i;
				}
				if (z.r * z.r + z.i * z.i < 4)
					img_putpixel(env, (t_pnt){x, y}, 0x000000);
				else
					img_putpixel(env, (t_pnt){x, y}, color_convert(color_get(0, (i * 4) % 256, 0, 0)));
				i = 0;
				z.r = 0;
				z.i = 0;
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
