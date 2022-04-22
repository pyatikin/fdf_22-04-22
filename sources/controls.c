/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 12:56:38 by vbrazhni          #+#    #+#             */
/*   Updated: 2022/04/22 20:56:12 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "mlx.h" for mlx_hook()
** "fdf.h" for key_press(), close(), mouse_press(), mouse_release() and
** mouse_move()
** <stdlib.h> for exit()
*/

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

/*
** Close window with 'X'
*/

int		ft_close(void *param)
{
	(void)param;
	exit(0);
}

/*
** Connect functions-controllers to window
*/

void	setup_controls(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, (1L<<0), key_press, fdf);
	//mlx_key_hook(fdf->win, key_press, fdf);
	mlx_hook(fdf->win, 17, 0, ft_close, fdf);
	mlx_hook(fdf->win, 4, (1L<<2), mouse_press, fdf);
	//mlx_hook(fdf->win, 5, (1L<<4), mouse_release, fdf);
	//mlx_hook(fdf->win, 6, (1L<<3), mouse_move, fdf);
}
