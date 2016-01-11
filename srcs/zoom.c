/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 21:52:53 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/12 00:27:44 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_env *env)
{
	t_img	new_img;
	int		max_x;
	int		max_y;
	int		x;
	int		y;

	x = 0;
	y = 0;
	max_x = WIDTH / 2;
	max_y = HEIGHT / 2;
	new_img.img = NULL;
	img_clear(env->mlx, &new_img);
	while (y < max_y)
	{
		while (x < max_x)
		{
			*(unsigned int *)(new_img.data + new_img.bpp * (x * 2) + new_img.sl * (y * 2)) = *(unsigned int*)(env->img.data + env->img.bpp * (x + WIDTH / 4) + env->img.sl * (y + HEIGHT / 4));
			x++;
		}
		x = 0;
		y++;
	}
	env->img = new_img;
}
