/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:48:24 by name              #+#    #+#             */
/*   Updated: 2022/07/21 17:03:24 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool    check_map_start(char **split)
{
    int    i;
    int    j;

    i = -1;
    j = -1;
    while (split[++i])
    {
        while (split[i][++j] == STANDARD_WALL_SYM || split[i][j] == STANDARD_FIELD_SYM);
        if (split[i][j])
            return (false);
    }
    return (true);
}

static bool    check_element_name(char **split, t_all *all,
        t_list *lst, int *index)
{
    int            i;
    const char    *values[] = {"NO", "SO", "WE", "EA", "F", "C"};

    if (check_map_start(split) && fs(split))
        return (true);
    if (!split[1] || split[2])
        return ((all->err = ft_strjoin("invalid element formatting: ",
                    lst->Dcur->content)), fs(split), true);
    i = -1;
    while (++i < 6)
    {
        if (!ft_strncmp(split[0], values[i], ft_strlen(values[i]) + 1))
            break ;
    }
    if (i == 6)
        return ((all->err = ft_strjoin("element does not exist: ", split[0])),
            fs(split), true);
    *index = i;
    return (false);
}

static bool    check_element_value(char **split, t_all *all, int *index)
{
    int            mapfd;
    const char    **rgb = NULL;

    if (*index < 4)
    {
        mapfd = open(split[1], O_RDONLY);
        if (mapfd < 0 || (read(mapfd, NULL, 0) < 0 && close(mapfd)))
            return ((all->err
                    = ft_strjoin("element value invalid: ", split[1])),
                fs(split), true);
        close(mapfd);
    }
    else
    {
        rgb = (const char **)ft_split(split[1], ',');
        if (((!rgb[1] || !rgb[2]) || (check_len_value((char **)rgb))
                || !(ft_atoi(rgb[0]) >= 0 && ft_atoi(rgb[0]) <= 255)
                || !(ft_atoi(rgb[1]) >= 0 && ft_atoi(rgb[1]) <= 255)
                || !(ft_atoi(rgb[2]) >= 0 && ft_atoi(rgb[2]) <= 255))
            && fs((char **)rgb))
            return ((all->err = ft_strjoin("invalid rgb values: ", split[1])),
                fs(split), true);
        fs((char **)rgb);
    }
    return (false);
}

static bool    set_element(char **split, t_all *all, t_list *lst, int *index)
{
    t_dlist    *next;
    t_dlist    *prev;

    if (*index < 4)
    {
        free(all->textures[*index]);
        all->textures[*index] = ft_strdup(split[1]);
    }
    else
    {
        set_colors(all, ft_split(split[1], ','), index);
    }
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
        if (lst->Dcur == lst->Dstart)
            lst->Dstart = next;
        ft_lstdeloneD(lst->Dcur, free);
        lst->Dcur = next;
    }
    return (false);
}

bool    setup_params(t_all *all, t_list *lst)
{
    static int    i = -1;
    char        **split;

    lst->Dcur = lst->Dstart;
    while (lst->Dcur)
    {
        if (ft_strlen(lst->Dcur->content) == 0 && go_next(lst))
            continue ;
        if (!lst->Dcur)
            break ;
        split = ft_split(lst->Dcur->content, ' ');
        if (check_element_name(split, all, lst, &i))
            if (all->err)
                return (true);
        else
            break ;
        else if (check_element_value(split, all, &i))
            return (true);
        else
            set_element(split, all, lst, &i);
        fs(split);
    }
    if (setup_missing(all))
        return (true);
    return (false);
}
