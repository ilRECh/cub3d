/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extra_regions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 23:44:53 by name              #+#    #+#             */
/*   Updated: 2022/07/21 14:00:25 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//'0' == 'A'
//'1' == 'B'
//all->plrpos.direction == 'Z'

#define ENCRYPTED_FIELD_SYM     'A'
#define ENCRYPTED_WALL_SYM      'B'
#define ENCRYPTED_PLAYER_SYM    'Z'
#define OUTSIDE_MAP_SYM         ' '

typedef struct s_any
{
    int    x;
    int    y;
}   t_any;

typedef enum e_mode
{
    _encrypt,
    _decrypt
}   t_mode;

static inline bool check_symbol(t_mode mode, int y, int x, t_all *all)
{
    if (all->map[y][x] == OUTSIDE_MAP_SYM)
        return (true);
    else if (mode == _encrypt)
    {
        if (all->map[y][x] == ENCRYPTED_FIELD_SYM
            || all->map[y][x] == ENCRYPTED_WALL_SYM
            || all->map[y][x] == ENCRYPTED_PLAYER_SYM)
            return (true);
    }
    else if (mode == _decrypt)
    {
        if (all->map[y][x] == STANDARD_FIELD_SYM
            || all->map[y][x] == STANDARD_WALL_SYM
            || all->map[y][x] == all->plrpos.direction)
            return (true);
    }
    return (false);
}

static void    proceed(t_mode mode, int y, int x, t_all *all)
{
    if (check_symbol(mode, y, x, all))
    {
        return ;
    }
    else if (mode == _encrypt)
    {
        if (all->map[y][x] == STANDARD_FIELD_SYM)
            all->map[y][x] = ENCRYPTED_FIELD_SYM;
        else if (all->map[y][x] == STANDARD_WALL_SYM)
            all->map[y][x] = ENCRYPTED_WALL_SYM;
        else if (all->map[y][x] == all->plrpos.direction)
            all->map[y][x] = ENCRYPTED_PLAYER_SYM;
    }
    else if (mode == _decrypt)
    {
        if (all->map[y][x] == ENCRYPTED_FIELD_SYM)
            all->map[y][x] = STANDARD_FIELD_SYM;
        else if (all->map[y][x] == ENCRYPTED_WALL_SYM)
            all->map[y][x] = STANDARD_WALL_SYM;
        else if (all->map[y][x] == ENCRYPTED_PLAYER_SYM)
            all->map[y][x] = all->plrpos.direction;
    }
    
    proceed(mode, y - 1, x, all);
    proceed(mode, y - 1, x - 1, all);
    proceed(mode, y, x - 1, all);
    proceed(mode, y + 1, x - 1, all);
    proceed(mode, y + 1, x, all);
    proceed(mode, y + 1, x + 1, all);
    proceed(mode, y, x + 1, all);
    proceed(mode, y - 1, x + 1, all);
}

static bool    find_any(t_any *any, t_all *all, t_mode mode)
{
    any->y = -1;
    while (all->map[++any->y])
    {
        any->x = -1;
        while (all->map[any->y][++any->x])
        {
            if ((mode == _encrypt && all->map[any->y][any->x] == STANDARD_FIELD_SYM)
				|| (mode == _decrypt && all->map[any->y][any->x] == ENCRYPTED_FIELD_SYM))
                return (true);
        }
    }
    return (false);
}

bool    check_extra_regions(t_all *all)
{
    t_any    any;

    find_any(&any, all, _encrypt);
    proceed(_encrypt, any.y, any.x, all);
    if (find_any(&any, all, _encrypt))
        return (true);
    find_any(&any, all, _decrypt);
    proceed(_decrypt, any.y, any.x, all);
    return (false);
}
