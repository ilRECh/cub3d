/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:46:38 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t nmemb, size_t size)
{
    void    *alloc_mem;
    size_t    total_bytes;

    if (nmemb * size > (size_t)0 - 1)
        return (NULL);
    total_bytes = nmemb * size;
    alloc_mem = malloc(total_bytes);
    if (!alloc_mem)
        return (NULL);
    ft_bzero(alloc_mem, total_bytes);
    return (alloc_mem);
}
