/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:57:39 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/14 18:37:37 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key1(int keycode, t_env *env)
{
	if (keycode == 100 || keycode == 2)
	{
		img_clear(env->mlx, &env->img);
		img_move(env, 0.05 * WIDTH, 0);
		env->done = 0;
	}
	if (keycode == 97 || keycode == 0)
	{
		img_clear(env->mlx, &env->img);
		img_move(env, 0.05 * (-WIDTH), 0);
		env->done = 0;
	}
	if (keycode == 119 || keycode == 13)
	{
		img_clear(env->mlx, &env->img);
		img_move(env, 0, 0.05 * -HEIGHT);
		env->done = 0;
	}
}

void	key2(int keycode, t_env *env)
{
	if (keycode == 115 || keycode == 1)
	{
		img_clear(env->mlx, &env->img);
		img_move(env, 0, 0.05 * HEIGHT);
		env->done = 0;
	}
	if (keycode == 65451 || keycode == 69)
	{
		env->iter += 25;
		img_clear(env->mlx, &env->img);
		env->done = 0;
	}
	if (keycode == 53)
		fractol_exit(&env);
}

int		key_hook(int keycode, t_env *env)
{
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
	key1(keycode, env);
	key2(keycode, env);
	return (1);
}
