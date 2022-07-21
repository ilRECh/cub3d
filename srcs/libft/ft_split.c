/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:09:02 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t    wrdcnt(char const *s, char c)
{
    size_t    count;
    char    in_word_flag;

    count = 0;
    in_word_flag = 0;
    while (*s && *s == c)
        s++;
    if (*s)
        count++;
    while (*s)
    {
        if (*s == c && *(s + 1) != c && *(s + 1) && !in_word_flag)
        {
            in_word_flag++;
            count++;
        }
        else if (*(s + 1) == c && in_word_flag)
            in_word_flag--;
        s++;
    }
    return (count);
}

static void    getword(const char **start, const char **end, char c)
{
    while (**start == c)
        (*start)++;
    *end = *start + 1;
    while (**end && **end != c)
        (*end)++;
}

static char    clear(char **to_clear, size_t size)
{
    while (size--)
        free(to_clear[size]);
    free(to_clear);
    return (1);
}

char    **ft_split(char const *s, char c)
{
    char        **result;
    size_t        result_size;
    size_t        iter_1;
    const char    *start;
    const char    *end;

    if (!s)
        return (NULL);
    result = (char **)ft_calloc(
            (result_size = wrdcnt(s, c)) + 1, sizeof(char *));
    if (!result)
        return (NULL);
    start = s;
    iter_1 = 0;
    while (iter_1 < result_size)
    {
        getword(&start, &end, c);
        result[iter_1] = ft_strndup(start, end - start);
        if (!result[iter_1++] && clear(result, result_size))
            break ;
        start = end + 1;
    }
    return (result);
}
