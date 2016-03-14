/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:01:28 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/14 17:09:26 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(void)
{
	ft_putendl("Usage:");
	ft_putendl("./fratol mandelbrot");
	ft_putendl("./fractol julia");
	ft_putendl("./fractol ship");
	exit(0);
}
