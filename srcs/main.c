/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:48:22 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/14 18:38:26 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_env *env)
{
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

int		motion_notify(int x, int y, t_env *env)
{
	img_clear(env->mlx, &env->img);
	env->julia_x = env->scn.a.x + ((double)x * env->scn.step_x);
	env->julia_y = env->scn.a.y + ((double)y * env->scn.step_y);
	env->done = 0;
	return (1);
}

int		init_env(t_env **env)
{
	if (!(*env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	(*env)->mlx = mlx_init();
	(*env)->win =
		mlx_new_window((*env)->mlx, WIDTH, HEIGHT, "mdos-san's fractol");
	(*env)->img.img = NULL;
	img_clear((*env)->mlx, &(*env)->img);
	(*env)->done = 0;
	(*env)->iter = 50;
	(*env)->i = 0;
	(*env)->c.r = 0;
	(*env)->c.i = 0;
	(*env)->z.r = 0;
	(*env)->z.i = 0;
	return (1);
}

void	init_fractol(t_env *env, char **av)
{
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
		mlx_hook(env->win, MOTION_NOTIFY, POINTER_MOTION,
				motion_notify, env);
		env->function = *draw_julia;
	}
	else if (ft_strcmp(av[1], "ship") == 0)
	{
		env->scn.a = (t_pnt){4, -2};
		env->scn.b = (t_pnt){-2, 2};
		env->function = *draw_ship;
		env->iter = 20;
	}
	else
		error();
}

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac == 2)
	{
		if (init_env(&env) == 0)
			fractol_exit(&env);
		init_fractol(env, av);
		env->scn.step_x = (env->scn.b.x - env->scn.a.x) / WIDTH;
		env->scn.step_y = (env->scn.b.y - env->scn.a.y) / HEIGHT;
		mlx_expose_hook(env->win, expose_hook, env);
		mlx_mouse_hook(env->win, mouse_hook, env);
		mlx_key_hook(env->win, key_hook, env);
		mlx_loop_hook(env->mlx, loop_hook, env);
		mlx_loop(env->mlx);
	}
	else
		error();
	return (0);
}
