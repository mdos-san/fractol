/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:19:27 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/06 17:24:40 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include "mlx.h"
# define WIDTH 600
# define HEIGHT 400

typedef struct	s_img
{
	void	*img;
	char	*data;
	int		bpp;
	int		sl;
	int		endian;
}				t_img;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_env;

#endif
