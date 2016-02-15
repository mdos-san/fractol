/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cel_assign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 21:53:14 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/15 08:59:16 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cel_assign(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			env->cel[x][y].z.r = 0;
			env->cel[x][y].z.i = 0;
			if (*(unsigned int*)(env->img.data + env->img.bpp * x + env->img.sl * y))
				env->cel[x][y].is_out = 1;
			else
				env->cel[x][y].is_out = 0;
			x++;
		}
		x = 0;
		y++;
	}
}
