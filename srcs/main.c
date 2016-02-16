/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:48:22 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/16 11:26:45 by mdos-san         ###   ########.fr       */
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
		env->function(env);
		expose_hook(env);
		env->done++;
	}
	return (1);
}

int	key_hook(int keycode, t_env *env)
{
	ft_putnbr(keycode);
	ft_putendl("<== keycode");
	if (keycode == 53)
		exit (0);
	if (keycode == 65362 || keycode == 126)
	{
		img_clear(env->mlx, &env->img);
		env->scn.a.x += env->scn.step_x * WIDTH / 4;
		env->scn.a.y += env->scn.step_y * HEIGHT / 4;
		env->scn.b.x -= env->scn.step_x * WIDTH / 4;
		env->scn.b.y -= env->scn.step_y * HEIGHT / 4;
		env->scn.step_x = (env->scn.b.x - env->scn.a.x) / WIDTH;
		env->scn.step_y = (env->scn.b.y - env->scn.a.y) / HEIGHT;
		env->done = 0;
	}
	if (keycode == 65362 || keycode == 125)
	{
		img_clear(env->mlx, &env->img);
		env->scn.a.x -= env->scn.step_x * WIDTH / 2;
		env->scn.a.y -= env->scn.step_y * HEIGHT / 2;
		env->scn.b.x += env->scn.step_x * WIDTH / 2;
		env->scn.b.y += env->scn.step_y * HEIGHT / 2;
		env->scn.step_x = (env->scn.b.x - env->scn.a.x) / WIDTH;
		env->scn.step_y = (env->scn.b.y - env->scn.a.y) / HEIGHT;
		env->done = 0;
	}
	if (keycode == 100 || keycode == 2)
	{
		img_clear(env->mlx, &env->img);
		img_move(env, WIDTH * 0.05, 0);
		env->done = 0;
	}
	if (keycode == 97 || keycode == 0)
	{
		img_clear(env->mlx, &env->img);
		img_move(env,  -WIDTH * 0.05, 0);
		env->done = 0;
	}
	if (keycode == 119 || keycode == 13)
	{
		img_clear(env->mlx, &env->img);
		img_move(env, 0, -HEIGHT * 0.05);
		env->done = 0;
	}
	if (keycode == 115 || keycode == 1)
	{
		img_clear(env->mlx, &env->img);
		img_move(env, 0, HEIGHT * 0.05);
		env->done = 0;
	}
	if (keycode == 65451 || keycode == 69)
	{
		env->iter += 25;
		env->done = 0;
	}
	return (1);
}

int	mouse_hook(int button, int x, int y, t_env *env)
{
	ft_putnbr(x - WIDTH / 2);
	ft_putendl("<== x");
	if (button == 5 || button == 1)
	{
		img_clear(env->mlx, &env->img);
		img_move(env, x - WIDTH / 2, y - HEIGHT / 2);
		env->scn.a.x += env->scn.step_x * (WIDTH / 4);
		env->scn.a.y += env->scn.step_y * (HEIGHT / 4);
		env->scn.b.x -= env->scn.step_x * (WIDTH / 4);
		env->scn.b.y -= env->scn.step_y * (HEIGHT / 4);
		env->scn.step_x = (env->scn.b.x - env->scn.a.x) / WIDTH;
		env->scn.step_y = (env->scn.b.y - env->scn.a.y) / HEIGHT;
		img_move(env, (x - WIDTH / 2) * -1, (y - HEIGHT / 2) * -1);
		env->done = 0;
	}
	if (button == 4 || button == 2)
	{
		img_clear(env->mlx, &env->img);
		env->scn.a.x -= env->scn.step_x * WIDTH / 2;
		env->scn.a.y -= env->scn.step_y * HEIGHT / 2;
		env->scn.b.x += env->scn.step_x * WIDTH / 2;
		env->scn.b.y += env->scn.step_y * HEIGHT / 2;
		env->scn.step_x = (env->scn.b.x - env->scn.a.x) / WIDTH;
		env->scn.step_y = (env->scn.b.y - env->scn.a.y) / HEIGHT;
		env->done = 0;
	}
	return (1);
}

int	motion_notify(int x, int y, t_env *env)
{
	img_clear(env->mlx, &env->img);
	env->julia_x = env->scn.a.x + ((double)x * env->scn.step_x);
	env->julia_y = env->scn.a.y + ((double)y * env->scn.step_y);
	env->done = 0;
	return (1);
}

int	main(int ac, char **av)
{
	t_env	*env;

	if (ac == 2)
	{
		if (!(env = (t_env *)malloc(sizeof(t_env))))
			return (0);
		env->mlx = mlx_init();
		env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "mdos-san's fractol");
		img_clear(env->mlx, &env->img);
		env->done = 0;
		env->iter = 50;
		env->i = 0;
		env->c.r = 0;
		env->c.i = 0;
		env->z.r = 0;
		env->z.i = 0;
		if (ft_strcmp(av[1], "mandelbrot") == 0)
		{
			env->scn.a = (t_pnt){2, -1};
			env->scn.b = (t_pnt){-1, 1};
			env->function = *draw_mandelbrot;
		}
		else if (ft_strcmp(av[1], "julia") == 0)
		{
			env->scn.a = (t_pnt){1.5, -1};
			env->scn.b = (t_pnt){-1.5, 1};
			mlx_hook(env->win, MOTION_NOTIFY, POINTER_MOTION, motion_notify, env);
			env->function = *draw_julia;
		}
		else if (ft_strcmp(av[1], "ship") == 0)
		{
			env->scn.a = (t_pnt){2, -1};
			env->scn.b = (t_pnt){-1, 1};
			env->function = *draw_ship;
			env->iter = 20;
		}
		env->scn.step_x = (env->scn.b.x - env->scn.a.x) / WIDTH;
		env->scn.step_y = (env->scn.b.y - env->scn.a.y) / HEIGHT;
		mlx_expose_hook(env->win, expose_hook, env);
		mlx_mouse_hook(env->win, mouse_hook, env);
		mlx_key_hook(env->win, key_hook, env);
		mlx_loop_hook(env->mlx, loop_hook, env);
		mlx_loop(env->mlx);
	}
	else
	{
		ft_putendl("Usage:");
		ft_putendl("./fratol mandelbrot");
		ft_putendl("./fractol julia");
		ft_putendl("./fractol ship");
	}
	return (0);
}
