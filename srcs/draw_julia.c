#include "fractol.h"

void	draw_julia(t_env *env, int nbr)
{
	t_cplx	z;
	t_cplx	c;
	double	tmp;
	t_scn	scn;
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	i = 0;
	scn = env->scn;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			if (*(unsigned int *)(env->img.data + env->img.bpp * x + env->img.sl * y) == 0x000000)
			{
				z.r = scn.a.x;
				z.i = scn.a.y;
				c.r = env->julia_x;
				c.i = env->julia_y;
				while (i < nbr && z.r * z.r + z.i * z.i < 4)
				{
					tmp = z.r;
					z.r = z.r * z.r - z.i * z.i + c.r;
					z.i = 2 * z.i * tmp + c.i;
					++i;
				}
				if (z.r * z.r + z.i * z.i < 4)
				{
					img_putpixel(env, (t_pnt){x, y}, 0x000000);
				}
				else
				{
					img_putpixel(env, (t_pnt){x, y}, color_convert(color_get((i * 12) % 256, (i * 24) % 256, (i * 42) % 256, 0)));
				}
				i = 0;
			}
			x++;
			scn.a.x += scn.step_x;
		}
		x = 0;
		scn.a.x = env->scn.a.x;
		y++;
		scn.a.y += scn.step_y;
	}
}
