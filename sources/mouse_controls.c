/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:29:19 by vbrazhni          #+#    #+#             */
/*   Updated: 2022/04/22 15:35:58 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_fdf type, zoom(), boolean values and draw()
** "key_macos.h" for mouse key codes
*/

#include "fdf.h"
#include "key_macos.h"

/*
** Handle mouse press
*/
#include <stdio.h>
int			mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;
	printf("button = %i\n", button);
	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, fdf);
	else if (button == MOUSE_LEFT_BUTTON)
		fdf->mouse->is_pressed = true;
	return (0);
}

/*
** Handle mouse release
*/

int			mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;
	printf("button = %i\n", button);
	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->mouse->is_pressed = false;
	return (0);
}

/*
** Handle mouse move
*/

int			mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;
	printf("x/y = %i, %i", x, y);
	fdf = (t_fdf *)param;
	fdf->mouse->previous_x = fdf->mouse->x;
	fdf->mouse->previous_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->is_pressed)
	{
		fdf->camera->beta += (x - fdf->mouse->previous_x) * 0.002;
		fdf->camera->alpha += (y - fdf->mouse->previous_y) * 0.002;
		draw(fdf->map, fdf);
	}
	return (0);
}
