/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:08:24 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char    *string_1;
    unsigned char    *string_2;

    string_1 = (unsigned char *)s1;
    string_2 = (unsigned char *)s2;
    while (n--)
    {
        if (*string_1 - *string_2)
            return (*string_1 - *string_2);
        string_1++;
        string_2++;
    }
    return (0);
}
