/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:08:31 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char    *destination;
    unsigned char    *source;

    if (!dest && !src)
        return (NULL);
    destination = (unsigned char *)dest;
    source = (unsigned char *) src;
    if (destination < source)
        while (n--)
            *destination++ = *source++;
    else
    {
        destination += n;
        source += n;
        while (n--)
            *--destination = *--source;
    }
    return (dest);
}
