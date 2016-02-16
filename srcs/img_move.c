/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 00:45:45 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/16 08:43:05 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_move(t_env *env, int mx, int my)
{
	t_img	new_img;
	int	x;
	int	y;

	x = 0;
	y = 0;
	new_img.img = NULL;
	env->scn.a.x += env->scn.step_x * mx;
	env->scn.b.x += env->scn.step_x * mx;
	env->scn.a.y += env->scn.step_y * my;
	env->scn.b.y += env->scn.step_y * my;
	img_clear(env->mlx, &new_img);
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			if (0 < x + mx && x + mx < WIDTH && 0 < y + my && y + my < HEIGHT)
				*(unsigned int *)(new_img.data + new_img.bpp * (x + mx) + new_img.sl * (y + my)) = *(unsigned int*)(env->img.data + env->img.bpp * x + env->img.sl * y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(env->mlx, env->img.img);
	env->img = new_img;
}
