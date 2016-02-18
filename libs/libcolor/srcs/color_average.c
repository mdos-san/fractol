#include "libcolor.h"

t_color	color_average(t_color a, t_color b)
{
	t_color	average;

	average.r = (unsigned char)((unsigned int)(a.r + b.r) / 2);
	average.g = (unsigned char)((unsigned int)(a.g + b.g) / 2);
	average.b = (unsigned char)((unsigned int)(a.b + b.b) / 2);
	average.a = (unsigned char)((unsigned int)(a.a + b.a) / 2);
	return (average);
}
