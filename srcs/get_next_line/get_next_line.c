/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:59:27 by csamuro           #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static uint8_t    del_elem(t_list_gnl **lst, int32_t fd)
{
    t_list_gnl    *tmp;

    while (*lst)
    {
        if ((*lst)->fd == fd)
            break ;
        lst = &(*lst)->next;
    }
    tmp = (*lst);
    if ((*lst)->next)
        *lst = (*lst)->next;
    else
        *lst = NULL;
    free(tmp->str);
    free(tmp);
    return (0);
}

static t_list_gnl    *new_elem(char *str, t_list_gnl *next, int32_t fd)
{
    t_list_gnl    *elem;

    elem = (t_list_gnl *)malloc(1 * sizeof(t_list_gnl));
    if (!elem)
        return (NULL);
    elem->next = next;
    elem->str = str;
    if (elem->str)
        elem->str[0] = 0;
    elem->fd = fd;
    return (elem);
}

static t_list_gnl    *rem_search(t_list_gnl *lst, int32_t fd)
{
    while (lst)
    {
        if (lst->fd == fd)
            return (lst);
        else if (lst->next && lst->next->fd > fd)
        {
            lst->next = new_elem(NULL, lst->next, fd);
            return (lst->next);
        }
        else if (!lst->next)
            break ;
        lst = lst->next;
    }
    if (lst)
    {
        lst->next = new_elem(NULL, NULL, fd);
        return (lst->next);
    }
    return (NULL);
}

static uint8_t    ft_retline(char **str, char **line)
{
    char    *n_pos;

    n_pos = gnl_strchr(*str, '\n');
    if (!n_pos)
    {
        if (!*str)
            *line = gnl_strndup("", 0);
        else
            *line = gnl_strndup(*str, gnl_strlen(*str));
        free(*str);
        *str = NULL;
        return (0);
    }
    *line = gnl_strndup(*str, n_pos - *str);
    if (!*line)
        return (1);
    n_pos = gnl_strndup(n_pos + 1, gnl_strlen(n_pos + 1));
    free(*str);
    *str = n_pos;
    return (0);
}

int    get_next_line(int fd, char **line)
{
    static t_list_gnl    *lst_head;
    t_list_gnl            *cur_elem;
    ssize_t                br;

    if (!lst_head || (lst_head->fd != BUF))
        lst_head = new_elem((char *)malloc(BUFFER_SIZE + 1), lst_head, BUF);
    if ((fd < 0 || fd > 260 || !line || !lst_head || !(lst_head->str)
            || (BUFFER_SIZE < 1)) && !del_elem(&lst_head, BUF))
        return (-1);
    cur_elem = rem_search(lst_head, fd);
    while (!gnl_strchr(lst_head->str, '\n') && !gnl_strchr(cur_elem->str, '\n'))
    {
        br = read(fd, lst_head->str, BUFFER_SIZE);
        lst_head->str[br] = 0;
        if (br <= 0)
            break ;
        cur_elem->str = gnl_strjoin(cur_elem->str, lst_head->str);
    }
    del_elem(&lst_head, BUF);
    if ((br < 0 && !del_elem(&lst_head, fd))
        || ft_retline(&cur_elem->str, line))
        return (-1);
    else if (br == 0 && !cur_elem->str)
        return (del_elem(&lst_head, fd));
    return (1);
}
