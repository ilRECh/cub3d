/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 22:26:55 by ilRECh            #+#    #+#             */
/*   Updated: 2022/07/22 12:23:44 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_draw_line(t_all *all, int x, int color)
{
	char	*dst;
	int i = 0;

	while (i < all->screen_sizey)
	{
		dst = all->img.addr + (i * all->img.line_length + x * (all->img.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
		i++;
	}
}

int render_next_frame(void *to_all)
{
    static int color = 0x00000000;
    t_all *all = to_all;

	mlx_draw_line(all, 960, color++);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->img.img, 0, 0);
    return (0);
}

bool initialize_game(t_all *all)
{
	all->mlx = mlx_init();
    mlx_get_screen_size(all->mlx, &all->screen_sizex, &all->screen_sizey);
	all->mlx_win = mlx_new_window(all->mlx, all->screen_sizex, all->screen_sizey, "Hero in  trouble");
	all->img.img = mlx_new_image(all->mlx, all->screen_sizex, all->screen_sizey);
	all->img.addr = mlx_get_data_addr(
		all->img.img,
		&all->img.bits_per_pixel,
		&all->img.line_length,
		&all->img.endian);
	mlx_do_key_autorepeatoff(all->mlx);
	// mlx_hook(all->mlx, KeyPress, KeyPressMask, hook_key_press, all);
	// mlx_hook(all->mlx, KeyRelease, KeyReleaseMask, hook_key_release, all);
	mlx_hook(all->mlx_win, DestroyNotify, StructureNotifyMask, hook_exit, all);		
	mlx_loop_hook(all->mlx, render_next_frame, all);
    mlx_loop(all->mlx);
    return (false);
}