/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 22:25:24 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:53:45 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//UP 0
//UPLEFT 1 
//LEFT 2
//DOWNLEFT 3 
//DOWN 4
//DOWNRIGHT 5 
//RIGHT 6
//UPRIGHT 7

static inline bool    err_at(int i, int j, t_all *all)
{
    char    *tmp[2];

    tmp[0] = ft_strndup(all->map[i - 1] + j - 1, 4);
    tmp[0][3] = '\n';
    tmp[1] = ft_strndup(all->map[i] + j - 1, 4);
    tmp[1][3] = '\n';
    all->err = ft_strjoin(tmp[0], tmp[1]);
    free(tmp[0]);
    free(tmp[1]);
    tmp[0] = ft_strndup(all->map[i + 1] + j - 1, 3);
    tmp[1] = all->err;
    all->err = ft_strjoin(all->err, tmp[0]);
    free(tmp[0]);
    free(tmp[1]);
    return (true);
}

static bool    check(int i, int j, t_all *all, bool go)
{
    static int            dir = 0;
    static const int    dirs[8][2] =
    {
        {-1, 0},
        {-1, -1},
        {0, -1},
        {1, -1},
        {1, 0},
        {1, 1},
        {0, 1},
        {-1, 1}
    };

    if (all->map[i][j] == ' ')
        return (true);
    else if (all->map[i][j] == '1')
        return (false);
    while (dir < 8)
    {
        if (check(i + dirs[dir][0], j + dirs[dir][1], all, false))
        {
            if (go)
                dir = 0;
            if (!all->err)
                err_at(i, j, all);
            return (true);
        }
        if (go)
            dir++;
        else
            return (false);
    }
    dir = 0;
    return (false);
}

bool    check_closed(t_all *all)
{
    int    i;
    int    j;

    i = -1;
    while (all->map[++i])
    {
        j = -1;
        while (all->map[i][++j])
        {
            if (all->map[i][j] == STANDARD_FIELD_SYM
                || all->map[i][j] == all->plrpos.direction)
                if (check(i, j, all, true))
                    return (true);
        }
    }
    return (false);
}
