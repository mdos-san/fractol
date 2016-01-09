#include "fractol.h"

void	draw_mandelbrot(t_env *env, t_scn scn, int iter)
{
	t_cplx	c;
	t_cplx	z;
	double	tmp_2;
	int		i;
	double	tmpx;
	double	tmpy;
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
			while (i < iter && z.r * z.r + z.i * z.i < 4)
			{
				tmpx = z.r * z.r - z.i * z.i - c.r;
				tmpy = 2 * z.i * z.r + c.i;
				if (tmpx == z.r && tmpy == z.i)
				{
					i = iter;
					break ;
				}
				z.r = tmpx;
				z.i = tmpy;
				++i;
			}
			if (i == iter)
				img_putpixel(env, (t_pnt){x, y}, 0x000000);
			else
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
