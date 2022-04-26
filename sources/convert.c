/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 17:16:15 by vbrazhni          #+#    #+#             */
/*   Updated: 2022/04/26 20:27:20 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_coord_val type, t_map type, terminate() and pop()
** "libft.h" for ssize_t type ("libft.h" includes <string.h>),
** size_t ("libft.h" includes <string.h>) and ft_memalloc()
** "error_message.h" for ERR_CONV_TO_ARR macros
** <stdlib.h> for free()
*/

#include "fdf.h"
#include "libft.h"
#include "error_message.h"
#include <stdlib.h>

/*
** Convert stack with t_coord_val elements (contains z value and color value)
** to array with z values and array with color values.
*/
void	maldop(t_map *map, int arr_size);

void	stack_to_arrays(t_coord_val **coords_stack, t_map *map)
{
	t_coord_val	*coord;
	size_t		i;
	size_t		arr_size;

	arr_size = map->width * map->height * sizeof(int);
	maldop(map, arr_size);
	i = map->width * map->height - 1;
	coord = pop(coords_stack);
	while (coord && i >= 0)
	{
		map->coords_arr[i] = coord->z;
		map->colors_arr[i] = coord->color;
		if (coord->z > map->z_max)
			map->z_max = coord->z;
		if (coord->z < map->z_min)
			map->z_min = coord->z;
		i--;
		free(coord);
		coord = pop(coords_stack);
	}
	map->z_range = map->z_max - map->z_min;
}

void	maldop(t_map *map, int arr_size)
{
	map->coords_arr = (int *)ft_memalloc(arr_size);
	if (!map->coords_arr)
		terminate(ERR_CONV_TO_ARR);
	map->colors_arr = (int *)ft_memalloc(arr_size);
	if (!map->colors_arr)
		terminate(ERR_CONV_TO_ARR);
}
