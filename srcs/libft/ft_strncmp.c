/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:09:49 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    ft_strncmp(const char *s1, const char *s2, size_t n)
{
    if (!s1 || !s2)
        return (0);
    while (n--)
        if (*s1++ - *s2++ || (!*s1 && !*s2))
            return ((unsigned char)*--s1 - (unsigned char)*--s2);
    return (0);
}
