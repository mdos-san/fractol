#include "fractol.h"

void	img_clear(void *mlx, t_img *img)
{
	if (img->img)
		mlx_destroy_image(mlx, img->img);
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->sl, &img->endian);
	img->bpp /= 8;
}
