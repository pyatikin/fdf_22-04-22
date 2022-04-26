#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include "color.h"

/*
** Put pixel into map image
*/
void	dldop(int *error, t_point	delta, t_point	*cur, t_point sign);

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

/*
** Draw line
*/

static void	draw_line(t_point f, t_point s, t_fdf *fdf)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = FT_ABS(s.x - f.x);
	delta.y = FT_ABS(s.y - f.y);
	sign.x = -1;
	if (f.x < s.x)
		sign.x = 1;
	sign.y = -1;
	if (f.y < s.y)
		sign.y = 1;
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		put_pixel(fdf, cur.x, cur.y, get_color(cur, f, s, delta));
		dldop(error, delta, &cur, sign);
	}
}

void	dldop(int *error, t_point	delta, t_point	*cur, t_point sign)
{
	error[1] = error[0];
	if (error[1] > -delta.y)
	{
		error[0] -= delta.y;
		cur->x += sign.x;
	}
	if (error[1] < delta.x)
	{
		error[0] += delta.x;
		cur->y += sign.y;
	}
}

/*
** Draw background colors (Menu background + main background)
*/

static void	draw_background(t_fdf *fdf)
{
	int	*image;
	int	i;

	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		image[i] = BACKGROUND;
		i++;
	}
}

/*
** Draw image
*/

void	draw(t_map *map, t_fdf *fdf)
{
	int		x;
	int		y;

	draw_background(fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != fdf->map->width - 1)
				draw_line(project(new_point(x, y, map), fdf),
					project(new_point(x + 1, y, map), fdf), fdf);
			if (y != fdf->map->height - 1)
				draw_line(project(new_point(x, y, map), fdf),
					project(new_point(x, y + 1, map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
