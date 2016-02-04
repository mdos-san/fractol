/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:48:22 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/12 01:44:25 by mdos-san         ###   ########.fr       */
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
	if (env->done == 0)
	{
		env->function(env, env->iter);
		expose_hook(env);
		env->done++;
	}
	return (1);
}

int	key_hook(int keycode, t_env *env)
{
	ft_putnbr(keycode);
	ft_putendl(" <= keycode");
	if (keycode == 53)
		exit (0);
	if (keycode == 65362 || keycode == 126)
	{
		zoom(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
		cel_assign(env);
		env->scn.a.x += env->scn.step_x * WIDTH / 4;
		env->scn.a.y += env->scn.step_y * HEIGHT / 4;
		env->scn.b.x -= env->scn.step_x * WIDTH /4;
		env->scn.b.y -= env->scn.step_y * HEIGHT /4;
		env->scn.step_x = (env->scn.b.x - env->scn.a.x) / WIDTH;
		env->scn.step_y = (env->scn.b.y - env->scn.a.y) / HEIGHT;
		env->done = 0;
	}
	if (keycode == 100 || keycode == 2)
	{
		img_move(env, - WIDTH * 0.05, 0);
		cel_assign(env);
		env->scn.a.x += env->scn.step_x * WIDTH * 0.05;
		env->scn.b.x += env->scn.step_x * WIDTH * 0.05;
		env->done = 0;
	}
	if (keycode == 97 || keycode == 0)
	{
		img_move(env, WIDTH * 0.05, 0);
		cel_assign(env);
		env->scn.a.x -= env->scn.step_x * WIDTH * 0.05;
		env->scn.b.x -= env->scn.step_x * WIDTH * 0.05;
		env->done = 0;
	}
	if (keycode == 119 || keycode == 13)
	{
		img_move(env, 0, HEIGHT * 0.05);
		cel_assign(env);
		env->scn.a.y -= env->scn.step_y * HEIGHT * 0.05;
		env->scn.b.y -= env->scn.step_y * HEIGHT * 0.05;
		env->done = 0;
	}
	if (keycode == 115 || keycode == 1)
	{
		img_move(env, 0, - HEIGHT * 0.05);
		cel_assign(env);
		env->scn.a.y += env->scn.step_y * HEIGHT * 0.05;
		env->scn.b.y += env->scn.step_y * HEIGHT * 0.05;
		env->done = 0;
	}
	if (keycode == 65451)
	{
		env->iter += 25;
		env->done = 0;
	}
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
	env->done = 0;
	env->iter = 50;
	env->function = *draw_mandelbrot;
	cel_assign(env);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop_hook(env->mlx, loop_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
