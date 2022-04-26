#include "../minilibx-linux/mlx_int.h"
#include "fdf.h"
#include "key_macos.h"
#include <stdlib.h>
#include <stdio.h>

/*
** Handle key press
*/

int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	myfree(key, fdf);
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS
		|| key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS)
		zoom(key, fdf);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
		|| key == ARROW_UP || key == ARROW_DOWN)
		move(key, fdf);
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1
		|| key == NUM_PAD_2 || key == MAIN_PAD_2
		|| key == NUM_PAD_3 || key == MAIN_PAD_3
		|| key == NUM_PAD_4 || key == MAIN_PAD_4
		|| key == NUM_PAD_6 || key == MAIN_PAD_6
		|| key == NUM_PAD_7 || key == MAIN_PAD_7
		|| key == NUM_PAD_8 || key == MAIN_PAD_8
		|| key == NUM_PAD_9 || key == MAIN_PAD_9)
		rotate(key, fdf);
	else if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
		flatten(key, fdf);
	else if (key == MAIN_PAD_P || key == MAIN_PAD_I)
		change_projection(key, fdf);
	return (0);
}

void	myfree(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_ESC)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->camera);
		free(fdf->map->colors_arr);
		free(fdf->map->coords_arr);
		free(fdf->map);
		free(fdf->mouse);
		free(fdf->mlx);
		free(fdf);
		exit(0);
	}
}
