/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:59:49 by csamuro           #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *gnl_strchr(const char *s, int c)
{
    unsigned char    character;

    if (!s)
        return (NULL);
    character = (unsigned char)c;
    while (*s != character && *s)
        s++;
    if (*s != character)
        return (NULL);
    return ((char *)s);
}

char    *gnl_strndup(const char *s, size_t len)
{
    char    *dst;
    char    *dst_copy;

    if (!s)
        return (NULL);
    dst = (char *)malloc((len + 1) * sizeof(char));
    if (!dst)
        return (NULL);
    dst[len] = 0;
    dst_copy = dst;
    while (len--)
        *dst_copy++ = *s++;
    return (dst);
}

size_t    gnl_strlen(const char *s)
{
    char    *end;

    if (!s)
        return (0);
    end = (char *)s;
    while (*end)
        end++;
    return (end - s);
}

size_t    gnl_strlcpy(char *dst, const char *src, size_t dst_size)
{
    size_t    source_len;

    if (!dst || !src)
        return (0);
    source_len = gnl_strlen(src);
    if (dst_size)
    {
        dst_size--;
        while (dst_size-- && *src)
            *dst++ = *src++;
        *dst = 0;
    }
    return (source_len);
}

char    *gnl_strjoin(char *s1, char *s2)
{
    size_t    result_size;
    char    *dst;

    if (!s1)
        s1 = gnl_strndup("", 0);
    if (!s1)
        return (NULL);
    result_size = gnl_strlen(s1) + gnl_strlen(s2);
    dst = (char *)malloc((result_size + 1) * sizeof(char));
    if (!dst)
        return (NULL);
    dst[result_size] = 0;
    gnl_strlcpy(dst + gnl_strlcpy(dst, s1, result_size + 1),
        s2, gnl_strlen(s2) + 1);
    free(s1);
    return (dst);
}
