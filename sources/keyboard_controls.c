/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:58:39 by vbrazhni          #+#    #+#             */
/*   Updated: 2022/04/25 19:46:05 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_fdf type, zoom(), move(), rotate(), flatten() and
** change_projection()
** "key_macos.h" for key codes
** <stdlib.h> for exit()
*/
#include "../minilibx-linux/mlx_int.h"
#include "fdf.h"
#include "key_macos.h"
#include <stdlib.h>

/*
** Handle key press
*/
#include <stdio.h>
int			key_press(int key, void *param)
{
	t_fdf	*fdf;
	
	//printf("key = %i\n", key);
	fdf = (t_fdf *)param;
	if (key == MAIN_PAD_ESC){
		mlx_destroy_image(fdf->mlx, fdf->img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->camera);
		free(fdf->data_addr);
		free(fdf->map->colors_arr);
		free(fdf->map->coords_arr);
		free(fdf->map);
		free(fdf->mouse);
		free(fdf->img);
		free(fdf->mlx);
		free(fdf->win);
		free(fdf);
		exit(0);
	}
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
