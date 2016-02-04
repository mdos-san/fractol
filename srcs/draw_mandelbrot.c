/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 21:53:11 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/12 00:29:24 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define CEL env->cel[x][y]

void	draw_mandelbrot(t_env *env, int nbr)
{
	t_cplx	c;
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
				while (i < nbr && CEL.z.r * CEL.z.r + CEL.z.i * CEL.z.i < 4)
				{
					c.r = scn.a.x;
					c.i = scn.a.y;
					tmp = CEL.z.r;
					CEL.z.r = CEL.z.r * CEL.z.r - CEL.z.i * CEL.z.i - c.r;
					CEL.z.i = 2 * CEL.z.i * tmp + c.i;
					++i;
				}
				if (CEL.z.r * CEL.z.r + CEL.z.i * CEL.z.i < 4)
				{
					CEL.z.r = 0;
					CEL.z.i = 0;
					img_putpixel(env, (t_pnt){x, y}, 0x000000);
				}
				else
				{
					img_putpixel(env, (t_pnt){x, y}, color_convert(color_get((i * 12) % 256, (i * 24) % 256, (i * 42) % 256, 0)));
					CEL.is_out = 1;
				}
				i = 0;
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
