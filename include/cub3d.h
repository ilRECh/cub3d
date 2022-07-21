/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:36:39 by name              #+#    #+#             */
/*   Updated: 2022/07/21 18:09:07 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define FLOOR 4
# define CEILLING 5
# define SCALE 64 // условный размер каждого квадратика в карте
# define SENS_RAY 0.01
# define DEBUG
# define STANDARD_FIELD_SYM '0'
# define STANDARD_WALL_SYM '1'

#ifdef __linux__
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307
#elif defined (__APPLE__)
#define KEY_W 13
#define KEY_A 2
#define KEY_S 1
#define KEY_D 0
#define KEY_ESC 53
#endif

///
///    DATA
///
typedef enum s_align
{
    UP = 0b00001,
    DOWN = 0b00010,
    LEFT = 0b00100,
    RIGHT = 0b01000,
    CENTER = 0b10000
}    t_align;

typedef struct s_image // структура для изображений
{
    void    *img;
    void    *addr;
    t_point size;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}    t_image;

typedef struct s_window //структура для окна
{
    void    *mlx;
    void    *win;
    void    *img;
    void    *addr;
    int     line_l;
    int     bpp;
    int     en;
}    t_window;

typedef struct s_all // структура для всего вместе
{
    char    **textures;
    int     **colors;
    char    **map;
    int     map_length;
    int     map_height;
    char    *err;
}    t_all;

///
///    PARSING
///
bool        parse(t_all *all, int fd);
bool        setup_all(t_all *all);
bool        setup_params(t_all *all, t_list *lst);
void        set_colors(t_all *all, char **rgb, int *index);
bool        go_next(t_list *lst);
bool        setup_map(t_all *all, t_list *lst);
bool        check_num(char *number);
bool        check_len_value(char **rgb);
bool        setup_missing(t_all *all);
bool        make_map_from_lst(t_all *all, t_list *lst);
bool        check_symbols(t_all *all, t_list *lst);
bool        check_closed(t_all *all);
void        spaces_to_walls(t_all *all);

///
/// CLEANING
///
bool flf(t_list *lst, int fd);
bool fs(char **split);
void shutdown(t_all *all, int status);

#endif //CUB3D_H
