/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:03:33 by name              #+#    #+#             */
/*   Updated: 2022/07/21 22:20:13 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool    parse(t_all *all, int fd)
{
    t_list    lst;
    char    *line;
    int        ret;

    ft_memset(&lst, 0, sizeof(lst));
    while (true)
    {
        ret = get_next_line(fd, &line);
        
        if (ret < 0)
        {
            all->err = ft_strdup("file corrupted while reading");
            return (true);
        }
        
        ft_lstadd_backD(&lst.Dstart, line);
        if (ret == 0)
            break ;
    }
    if (setup_params(all, &lst))
        return (flf(&lst, fd), true);
    if (setup_map(all, &lst))
        return (flf(&lst, fd), true);
    return (flf(&lst, fd), false);
}
