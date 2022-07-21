/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:22:17 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strndup(const char *s, size_t len)
{
    char    *dst;
    char    *dst_copy;

    if (!s)
        return (NULL);
    dst = (char *)ft_calloc(len + 1, sizeof(char));
    if (!dst)
        return (NULL);
    dst_copy = dst;
    while (len--)
        *dst_copy++ = *s++;
    return (dst);
}
