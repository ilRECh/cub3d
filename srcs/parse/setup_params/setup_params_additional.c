/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_params_additional.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:08:48 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline bool    check_num(char *number)
{
    while (number && *number)
        if (!ft_isdigit(*number++))
            return (false);
    return (true);
}

inline bool    check_len_value(char **rgb)
{
    return ((ft_strlen(rgb[0]) > 3 || ft_strlen(rgb[0]) < 1
            || !check_num(rgb[0]))
        || (ft_strlen(rgb[1]) > 3 || ft_strlen(rgb[1]) < 1
            || !check_num(rgb[1]))
        || (ft_strlen(rgb[2]) > 3 || ft_strlen(rgb[2]) < 1
            || !check_num(rgb[2])));
}

inline void    set_colors(t_all *all, char **rgb, int *index)
{
    all->colors[*index] = ft_calloc(3, sizeof(unsigned char));
    all->colors[*index][0] = ft_atoi(rgb[0]);
    all->colors[*index][1] = ft_atoi(rgb[1]);
    all->colors[*index][2] = ft_atoi(rgb[2]);
    fs((char **)rgb);
}

inline bool    go_next(t_list *lst)
{
    lst->Dcur = lst->Dcur->next;
    if (lst->Dcur && lst->Dcur->prev == lst->Dstart)
        lst->Dstart = lst->Dcur;
    else if (!lst->Dcur)
        return (false);
    ft_lstdeloneD(lst->Dcur->prev, free);
    return (true);
}
