/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:09:15 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t    result_size;
    char    *dst;

    if (!s1 || !s2)
        return (NULL);
    result_size = ft_strlen(s1) + ft_strlen(s2) + 1;
    dst = (char *)ft_calloc(result_size, sizeof(char));
    if (!dst)
        return (NULL);
    ft_strlcpy(dst, s1, result_size);
    ft_strlcat(dst, s2, result_size);
    return (dst);
}
