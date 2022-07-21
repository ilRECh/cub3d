/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:26:25 by name              #+#    #+#             */
/*   Updated: 2022/07/21 17:44:34 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool    flf(t_list *lst, int fd)
{
    ft_lstclearD(&lst->Dstart, free);
    close(fd);
    return (true);
}

bool    fs(char **split)
{
    int    i;

    i = -1;
    while (split && split[++i])
    {
        free(split[i]);
        (split[i] = NULL);
    }
    free(split);
    return (true);
}

void shutdown(t_all *all, int status)
{
    int i;

    if (all)
    {
        if (all->err)
        {
            printf("%s\n", all->err);
        }
        i = -1;
        while (all->textures[++i])
            free(all->textures[i]);
        free(all->textures);
        i = -1;
        while (all->colors[++i])
            free(all->colors[i]);
        free(all->colors);
        i = -1;
        while (all->map && all->map[++i])
            free(all->map[i]);
        free(all->map);
        free(all->err);
    }
    exit(status);
}
