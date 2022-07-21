/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:09:45 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int n, char c))
{
    char    *result;
    size_t    iter_1;

    if (!s || !f)
        return (NULL);
    result = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
    if (!result)
        return (NULL);
    iter_1 = -1;
    while (s[++iter_1])
        result[iter_1] = (*f)(iter_1, s[iter_1]);
    return (result);
}        
