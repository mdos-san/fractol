/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_putpixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 21:53:07 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/11 21:57:49 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_putpixel(t_env *env, t_pnt pnt, int color)
{
	if ((0 <= pnt.x && pnt.x < WIDTH) && (0 <= pnt.y && pnt.y < HEIGHT))
		*(unsigned int*)(env->img.data +
		(int)(pnt.x) * env->img.bpp +
		env->img.sl * (int)(pnt.y)) = mlx_get_color_value(env->mlx, color);
}
