/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:22:37 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    char        *dst;
    char const    *start;
    char const    *end;

    if (!s1 || !set)
        return (NULL);
    start = s1;
    end = s1 + ft_strlen(s1);
    while (ft_strchr(set, *start) && *start)
        start++;
    if (start != end)
        while (ft_strchr(set, *(end - 1)))
            end--;
    dst = ft_strndup(start, end - start);
    return (dst);
}
