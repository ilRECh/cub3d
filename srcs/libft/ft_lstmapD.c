/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmapD.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:24:49 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist    *ft_lstmapD(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
    t_dlist    *new_lst;
    t_dlist    *tmp;

    if (!lst || !f)
        return (NULL);
    new_lst = ft_lstnewD(NULL);
    tmp = new_lst;
    while (lst)
    {
        tmp->content = (*f)(lst->content);
        if (del)
            (*del)(lst->content);
        if (lst->next)
        {
            tmp->next = ft_lstnewD(NULL);
            tmp->next->prev = tmp;
        }
        tmp = tmp->next;
        lst = lst->next;
    }
    return (new_lst);
}
