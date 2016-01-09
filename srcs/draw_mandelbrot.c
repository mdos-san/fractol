#include "fractol.h"
#define CEL env->cel[x][y]

void	draw_mandelbrot(t_env *env)
{
	t_cplx	c;
	double	tmp;
	t_scn	scn;
	unsigned int		*color;
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	scn = env->scn;
	i = env->iter++;
	color = (unsigned int *)malloc(sizeof(unsigned int));
	*((unsigned char*)color + 0) = i * 255 / 100;
	*((unsigned char*)color + 1) = 0;
	*((unsigned char*)color + 2) = 0;
	*((unsigned char*)color + 3) = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			if (!CEL.is_out)
			{
				c.r = scn.a.x;
				c.i = scn.a.y;
				tmp = CEL.z.r;
				CEL.z.r = CEL.z.r * CEL.z.r - CEL.z.i * CEL.z.i - c.r;
				CEL.z.i = 2 * CEL.z.i * tmp + c.i;
				if (CEL.z.r * CEL.z.r + CEL.z.i * CEL.z.i < 4)
					img_putpixel(env, (t_pnt){x, y}, 0x000000);
				else
				{
					img_putpixel(env, (t_pnt){x, y}, *color);
					CEL.is_out = 1;
				}
			}
			x++;
			scn.a.x += scn.step_x;
		}
		x = 0;
		scn.a.x = env->scn.a.x;
		y++;
		scn.a.y += scn.step_y;
	}
	free(color);
}
