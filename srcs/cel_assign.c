#include "fractol.h"

void	cel_assign(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			env->cel[x][y].z.r = 0;
			env->cel[x][y].z.i = 0;
			env->cel[x][y].is_out = 0;
			x++;
		}
		x = 0;
		y++;
	}
}
