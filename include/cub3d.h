/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:36:39 by name              #+#    #+#             */
/*   Updated: 2022/07/22 00:17:54 by ilRECh           ###   ########.fr       */
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
typedef struct s_point // структура для точки | и размеров
{
    int x;
    int y;
} t_point;

typedef struct s_dpoint // структура для точки | и размеров
{
    double x;
    double y;
} t_dpoint;

typedef struct s_image // структура для изображений
{
    void *img;
    void *addr;
    t_point size;
    int bits_per_pixel;
    int line_length;
    int endian;
}    t_image;

typedef struct s_window //структура для окна
{
    void *mlx;
    void *win;
    void *img;
    void *addr;
    int line_l;
    int bpp;
    int en;
} t_window;

typedef struct s_player
{
    float x;
    float y;
    float direction;
    float start;
    float end;
} t_player;

typedef struct s_all // структура для всего вместе
{
    t_window *win;
    t_point screen_size;
    char **textures;
    int **colors;
    char **map;
    int map_length;
    int map_height;
    t_point map_size;
    struct s_plrpos
    {
        int x;
        int y;
        char direction;
    } parsing_player_position; 
    t_player player_in_game;
    char *err;
}  t_all;

///
///    PARSING
///
bool parse(t_all *all, int fd);
bool setup_all(t_all *all);
bool setup_params(t_all *all, t_list *lst);
void set_colors(t_all *all, char **rgb, int *index);
bool go_next(t_list *lst);
bool setup_map(t_all *all, t_list *lst);
bool check_num(char *number);
bool check_len_value(char **rgb);
bool setup_missing(t_all *all);
bool make_map_from_lst(t_all *all, t_list *lst);
bool check_symbols(t_all *all, t_list *lst);
bool check_closed(t_all *all);
void spaces_to_walls(t_all *all);

///
/// CLEANING
///
bool flf(t_list *lst, int fd);
bool fs(char **split);
void shutdown(t_all *all, int status);

//
// GAME
//
void run(char *map);
bool initialize_game(t_all *all);

#endif //CUB3D_H
