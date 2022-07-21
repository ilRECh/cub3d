/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:04:26 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void    i_hate_norminette(t_all *all, char *line, int i, int j)
{
    all->plrpos.direction = line[j];
    all->plrpos.x = j + 1;
    all->plrpos.y = i + 1;
}

static bool    check(t_all *all, char *line, int i)
{
    int        j;
    char    tmp[2];

    j = -1;
    tmp[1] = 0;
    while (line && line[++j])
    {
        if (line[j] != ' ' && line[j] != '1' && line[j] != '0')
        {
            if (line[j] != 'W' && line[j] != 'E'
                && line[j] != 'N' && line[j] != 'S')
                return ((all->err = ft_strjoin("wrong character appeared: ",
                            ((line[j + 1] = 0), line + j))), true);
            else if (!all->plrpos.direction)
                i_hate_norminette(all, line, i, j);
            else
                return ((all->err
                        = ft_strjoin("there can be only one player, it is ",
                            (tmp[0] = all->plrpos.direction, tmp))), true);
        }
    }
    return (false);
}

bool    check_symbols(t_all *all, t_list *lst)
{
    int    i;

    i = 0;
    lst->Dcur = lst->Dstart;
    while (lst->Dcur)
    {
        if (check(all, lst->Dcur->content, i))
            return (true);
        lst->Dcur = lst->Dcur->next;
        i++;
    }
    if (!all->plrpos.direction)
        return ((all->err = ft_strdup("there is no player")), true);
    return (false);
}
