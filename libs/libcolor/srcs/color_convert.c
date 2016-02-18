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
