#include "fdf.h"

float	ft_abs(float x)
{
	if (x >= 0)
		return (x);
	else
		return (-1.0 * x);
}

static void	buttom_hook(int key_button, t_fdf *field)
{
	if (key_button == 126)
		field->place_y -= 50;
	if (key_button == 125)
		field->place_y += 50;
	if (key_button == 124)
		field->place_x += 50;
	if (key_button == 123)
		field->place_x -= 50;
	if (key_button == 1)
		field->corn += 0.05;
	if (key_button == 2)
		field->corn -= 0.05;
	if (key_button == 4)
		field->zooming -= 5;
	if (key_button == 5)
		field->zooming += 5;
}

int	key(int key_button, t_fdf *field)
{
	int	j;

	j = 0;
	buttom_hook(key_button, field);
	if (key_button == 53)
	{
		mlx_destroy_window(field->mlx_ptr, field->win_ptr);
		while (j < field->hight)
		{
			free(field->matrix[j]);
			j++;
		}
		free(field->matrix);
		exit(0);
	}
	mlx_destroy_image(field->mlx_ptr, field->img);
	mlx_clear_window(field->mlx_ptr, field->win_ptr);
	field->img = mlx_new_image(field->mlx_ptr, 1000, 1000);
	//draw(*field);
	mlx_put_image_to_window(field->mlx_ptr, field->win_ptr, field->img, 0, 0);
	return (0);
}

int	mouse(int key_button, int x, int y, t_fdf *field)
{
	x = 0;
	y = 0;
	key(key_button, field);
	return (0);
}

int	ft_close(t_fdf *field)
{
	int	j;

	j = 0;
	mlx_destroy_image(field->mlx_ptr, field->img);
	mlx_destroy_window(field->mlx_ptr, field->win_ptr);
	while (j < field->hight)
	{
		free(field->matrix[j]);
		j++;
	}
	free(field->matrix);
	exit(0);
}

int	main(int argv, char **argc)
{
	t_fdf	field;
	
	if(argv != 2)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	field = main_reader(argc[1]);
	///
	int pixel_bits = 32;
	int line_bytes = field.width*4;
	int endian = 0;
	///
	field.zooming = 1;
	field.place_x = 0;
	field.place_y = 0;
	field.corn = 0.8;
	field.delta = 65535;
	
	field.mlx_ptr = mlx_init();
	field.win_ptr = mlx_new_window(field.mlx_ptr, 1000, 1000, "FDF");
	field.img = mlx_new_image(field.mlx_ptr, 1000, 1000);
	
	char *image_buff = mlx_get_data_addr(field.img, &pixel_bits, &line_bytes, &endian);
	int i=0;
	while(i<1000000)
	{image_buff[i]=0x00ff1576;}
	//write(1, &image_buff[0], 1);
	
	//draw(field, &image_buff);
	
	mlx_put_image_to_window(field.mlx_ptr, field.win_ptr, field.img, 0, 0);
	//mlx_key_hook(field.win_ptr, key, &field);
	//mlx_mouse_hook(field.win_ptr, mouse, &field);
	mlx_hook(field.win_ptr, 17, 0, ft_close, &field);
	mlx_loop(field.mlx_ptr);
	return (0);
}
