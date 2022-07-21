/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:49:06 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool    del_empty_from_end(t_all *all, t_list *lst)
{
    t_dlist    *next;
    t_dlist    *prev;

    lst->Dcur = ft_lstlastD(lst->Dstart);
    while (lst->Dcur && !ft_strlen(lst->Dcur->content))
    {
        next = lst->Dcur->next;
        prev = lst->Dcur->prev;
        if (!next && !prev)
        {
            lst->Dstart = NULL;
            ft_lstdeloneD(lst->Dcur, free);
            lst->Dcur = NULL;
        }
        else
        {
            ft_lstdeloneD(lst->Dcur, free);
            lst->Dcur = prev;
        }
    }
    if (!lst->Dcur)
        return ((all->err = ft_strdup("file does not contain a map")), true);
    return (false);
}

bool    setup_map(t_all *all, t_list *lst)
{
    char    *tmp;

    if (del_empty_from_end(all, lst))
        return (true);
    if (make_map_from_lst(all, lst))
        return (true);
    spaces_to_walls(all);
    if (check_closed(all))
        return ((all->err
                = ft_strjoin("the map is not closed properly:\n",
                    (tmp = all->err))),
            free(tmp), true);
    if (check_extra_regions(all))
        return ((all->err = ft_strdup("extra regions aren't supported")), true);
    return (false);
}
