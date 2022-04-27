#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include "error_message.h"

/*
** Initialize t_map element
*/

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (!map)
		terminate(ERR_MAP_INIT);
	map->width = 0;
	map->height = 0;
	map->coords_arr = NULL;
	map->colors_arr = NULL;
	map->z_min = FT_INT_MAX;
	map->z_max = FT_INT_MIN;
	map->z_range = 0;
	return (map);
}

/*
** Initialize t_fdf element
*/

t_fdf	*fdf_init(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	if (!fdf)
		terminate(ERR_FDF_INIT);
	fdf->mlx = mlx_init();
	if (!(fdf->mlx))
		terminate(ERR_FDF_INIT);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
	if (!(fdf->win))
		terminate(ERR_FDF_INIT);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!(fdf->img))
		terminate(ERR_FDF_INIT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->size_line), &(fdf->endian));
	fdf->map = map;
	fdf->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse));
	if (!(fdf->mouse))
		terminate(ERR_FDF_INIT);
	return (fdf);
}

/*
** Initialize t_camera element
*/

t_camera	*camera_init(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)ft_memalloc(sizeof(t_camera));
	if (!(camera))
		terminate(ERR_CAMERA_INIT);
	camera->zoom = ft_min((WIDTH - MENU_WIDTH) / fdf->map->width / 2,
			HEIGHT / fdf->map->height / 2);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	return (camera);
}
