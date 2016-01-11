/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:48:22 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/11 19:01:49 by mdos-san         ###   ########.fr       */
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
	draw_mandelbrot(env);
	expose_hook(env);
//	exit(0);
	return (1);
}

int	key_hook(int keycode, t_env *env)
{
	ft_putnbr(keycode);
	ft_putendl(" <= keycode");
	if (keycode == 65362 || keycode == 126)
	{
		img_clear(env->mlx, &env->img);
		cel_assign(env);
		env->scn.a.x += env->scn.step_x * WIDTH / 4;
		env->scn.a.y += env->scn.step_y * HEIGHT / 4;
		env->scn.b.x -= env->scn.step_x * WIDTH /4;
		env->scn.b.y -= env->scn.step_y * HEIGHT /4;
		env->scn.step_x = (env->scn.b.x - env->scn.a.x) / WIDTH;
		env->scn.step_y = (env->scn.b.y - env->scn.a.y) / HEIGHT;
		env->iter = 0;
	}
	if (keycode == 100 || keycode == 2)
	{
		img_clear(env->mlx, &env->img);
		cel_assign(env);
		env->scn.a.x += env->scn.step_x * 10;
		env->scn.b.x += env->scn.step_x * 10;
		env->iter = 0;
	}
	if (keycode == 97 || keycode == 0)
	{
		img_clear(env->mlx, &env->img);
		cel_assign(env);
		env->scn.a.x -= env->scn.step_x * 10;
		env->scn.b.x -= env->scn.step_x * 10;
		env->iter = 0;
	}
	if (keycode == 119 || keycode == 13)
	{
		img_clear(env->mlx, &env->img);
		cel_assign(env);
		env->scn.a.y -= env->scn.step_y * 10;
		env->scn.b.y -= env->scn.step_y * 10;
		env->iter = 0;
	}
	if (keycode == 115 || keycode == 1)
	{
		img_clear(env->mlx, &env->img);
		cel_assign(env);
		env->scn.a.y += env->scn.step_y * 10;
		env->scn.b.y += env->scn.step_y * 10;
		env->iter = 0;
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
	env->iter = 0;
	cel_assign(env);
	ft_putendl("cel_assign [DONE]");
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop_hook(env->mlx, loop_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
