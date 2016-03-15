/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:27:01 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/15 15:27:02 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"

unsigned int	color_convert(t_color color)
{
	unsigned int	converted;

	*((unsigned char*)&converted + 0) = color.g;
	*((unsigned char*)&converted + 1) = color.b;
	*((unsigned char*)&converted + 2) = color.r;
	*((unsigned char*)&converted + 3) = color.a;
	return (converted);
}
