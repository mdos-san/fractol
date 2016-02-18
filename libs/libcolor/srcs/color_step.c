#include "libcolor.h"

t_color	color_step(t_color c_a, t_color c_b, int nbr_stp, int act_stp)
{
	t_color	step;
	double		r;
	double		g;
	double		b;

	r = ((double)c_b.r - (double)c_a.r) / (double)nbr_stp;
	g = ((double)c_b.g - (double)c_a.g) / (double)nbr_stp;
	b = ((double)c_b.b - (double)c_a.b) / (double)nbr_stp;
	if (nbr_stp > 1)
	{
		step.r = (unsigned char)((double)c_a.r + (r * (double)act_stp));
		step.g = (unsigned char)((double)c_a.g + (g * (double)act_stp));
		step.b = (unsigned char)((double)c_a.b + (b * (double)act_stp));
		step.a = 0;
	}
	else
	{
		step.r = c_a.r;
		step.g = c_a.g;
		step.b = c_a.b;
		step.a = c_a.a;
	}
	return (step);
}
