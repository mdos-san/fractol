/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:52:38 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/14 17:55:37 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
