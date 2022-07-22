/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:05:08 by ilRECh            #+#    #+#             */
/*   Updated: 2022/07/22 17:29:48 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int hook_key_press(int key_code, t_all *all)
{
    if (key_code && all)
    {
        
    }
    return (0);
}

int hook_key_release(int key_code, t_all *all)
{
    if (key_code && all)
    {
        
    }
    return (0);
}

int hook_exit(void *all)
{
    shutdown(all, 0);
    return (0);
}
