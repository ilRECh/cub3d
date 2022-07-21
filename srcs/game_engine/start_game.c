/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:20:05 by ilRECh            #+#    #+#             */
/*   Updated: 2022/07/21 17:58:57 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool setup_all(t_all *all)
{
    all->textures = ft_calloc(7, sizeof (char *));
    if (!all->textures)
        return (true);
    all->colors = ft_calloc(7, sizeof(unsigned char *));
    if (!all->colors)
        return (true);
    all->plrpos.direction = 0;
    all->plrpos.x = -1;
    all->plrpos.y = -1;
    all->map = NULL;
    all->err = NULL;
    return (false);
}

int check_map_file(char *map)
{
    int fd = -1;

    if (!ft_strrchr(map, '.') || ft_strncmp(ft_strrchr(map, '.') + 1, "cub", 4))
    {
        printf(RED "Error\n" RESET "invalid file: %s\n", map);
        return (1);
    }
    
    fd = open(map, O_RDONLY);
    
    if (!fd || (read(fd, NULL, 0) < 0 && !close(fd)))
    {
        printf(RED "Error\n" RESET "invalid file: %s\n", map);
        return (1);
    }

    return (fd);
}

void cub3d(char *map)
{
    static t_all all = {0};

    if (setup_all(&all))
    {
        printf("%s\n", RED "Error\n" RESET "no space left\n");
        shutdown(&all, EXIT_FAILURE);
    }
    
    if (parse(&all, check_map_file(map)))
    {
        printf(RED "Error\n" RESET "invalid file formatting: %s\n", map);
        shutdown(&all, EXIT_FAILURE);
    }
}
