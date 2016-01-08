#include "fractol.h"

void	draw_mandelbrot(t_env *env, t_scn scn)
{
	t_cplx	c;
	t_cplx	z;
	double	tmp;
	double	tmp_2;
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	tmp_2 = scn.a.x;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			i = 0;
			c.r = scn.a.x;
			c.i = scn.a.y;
			z.r = 0;
			z.i = 0;
			while (i < 50 && z.r * z.r + z.i * z.i < 4)
			{
				tmp = z.r;
				z.r = z.r * z.r - z.i * z.i - c.r;
				z.i = 2 * z.i * tmp + c.i;
				++i;
			}
			if (i == 50)
				img_putpixel(env, (t_pnt){x, y}, 0xFFFFFF);
			x++;
			scn.a.x += scn.step_x;
		}
		x = 0;
		scn.a.x = tmp_2;
		y++;
		scn.a.y += scn.step_y;
	}
}
