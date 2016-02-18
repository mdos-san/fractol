#include "libcolor.h"

void	color_del(t_color **addr)
{
	if (*addr)
		free(*addr);
	*addr = NULL;
}
