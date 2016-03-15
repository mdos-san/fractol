/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:28:44 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/14 18:44:51 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_exit(t_env **env)
{
	if (*env)
	{
		if ((*env)->img.img)
			mlx_destroy_image((*env)->mlx, (*env)->img.img);
		ft_putendl("Image is destroyed.");
		if ((*env)->win)
			mlx_destroy_window((*env)->mlx, (*env)->win);
		ft_putendl("Window is destroyed.");
		free(*env);
		ft_putendl("env var freed.");
		ft_putendl("<3 Good bye dear corrector <3");
	}
	exit(0);
}
