/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:27:11 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/15 15:29:25 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"

t_color	color_get(unsigned char r,
					unsigned char b,
					unsigned char g,
					unsigned char a)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}
