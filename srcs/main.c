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

int	expose_hook(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (1);
}

int	loop_hook(t_env *env)
{
	img_clear(env->mlx, &env->img);
	draw_mandelbrot(env, env->scn, env->iter);
	expose_hook(env);
	exit(0);
	return (1);
}

int	key_hook(int keycode, t_env *env)
{
	ft_putnbr(keycode);
	ft_putendl(" <= keycode");
	if (keycode == 65362)
	{
		env->scn.a.x += env->scn.step_x * WIDTH / 10;
		env->scn.a.y += env->scn.step_y * HEIGHT / 10;
		env->scn.b.x -= env->scn.step_x * WIDTH / 10;
		env->scn.b.y -= env->scn.step_y * HEIGHT / 10;
		env->scn.step_x = (env->scn.b.x - env->scn.a.x) / WIDTH;
		env->scn.step_y = (env->scn.b.y - env->scn.a.y) / HEIGHT;
	}
	if (keycode == 49)
		env->iter++;
	if (keycode == 50)
		env->iter--;
	return (1);
}

int	main(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "mdos-san's fractol");
	img_clear(env->mlx, &env->img);
	env->scn.a = (t_pnt){2, -1};
	env->scn.b = (t_pnt){-1, 1};
	env->scn.step_x = (env->scn.b.x - env->scn.a.x) / WIDTH;
	env->scn.step_y = (env->scn.b.y - env->scn.a.y) / HEIGHT;
	env->iter = 1000;
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop_hook(env->mlx, loop_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
