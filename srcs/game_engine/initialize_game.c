/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 22:26:55 by ilRECh            #+#    #+#             */
/*   Updated: 2022/07/22 00:58:32 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef __APPLE__
void get_screen_size()
{
    
}
#elif defined (__linux__)
void get_screen_size()
{
    
}
#endif

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int render_next_frame(void *to_all)
{
    static int color = 0x00000000;
    t_all *all = to_all;
    t_image	img;
	img.img = mlx_new_image(all->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, color++);
	mlx_put_image_to_window(all->mlx, all->mlx_win, img.img, 0, 0);
    return (0);
}

bool initialize_game(t_all *all)
{
	all->mlx = mlx_init();
	all->mlx_win = mlx_new_window(all->mlx, 1920, 1080, "Hello world!");
	mlx_loop_hook(all->mlx, render_next_frame, all);
    mlx_loop(all->mlx);
    return (false);
}