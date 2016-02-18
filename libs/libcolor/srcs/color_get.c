#include "libcolor.h"

t_color	color_get(unsigned char r, unsigned char b, unsigned char g, unsigned char a)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}
