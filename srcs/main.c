/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:48:22 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/06 18:05:24 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_env	*env;
	t_scn	scn;

	scn.a = (t_pnt){2, -1};
	scn.b = (t_pnt){-1, 1};
	scn.step_x = (scn.b.x - scn.a.x) / WIDTH;
	scn.step_y = (scn.b.y - scn.a.y) / HEIGHT;
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "mdos-san's fractol");
	img_clear(env->mlx, &env->img);
	draw_mandelbrot(env, scn);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	mlx_loop(env->mlx);
	return (0);
}
