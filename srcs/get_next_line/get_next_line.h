/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:59:42 by csamuro           #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

# define BUFFER_SIZE 100

enum
{
    BUF = -42,
};

typedef struct s_list_gnl
{
    int32_t                fd;
    char                *str;
    struct s_list_gnl    *next;
}    t_list_gnl;

int        get_next_line(int fd, char **line);
char    *gnl_strchr(const char *s, int c);
char    *gnl_strndup(const char *s, size_t len);
size_t    gnl_strlen(const char *s);
size_t    gnl_strlcpy(char *dst, const char *src, size_t dst_size);
char    *gnl_strjoin(char *s1, char *s2);

#endif