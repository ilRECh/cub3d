/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmapS.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:06:44 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slist    *ft_lstmapS(t_slist *lst, void *(*f)(void *), void (*del)(void *))
{
    t_slist    *new_lst;
    t_slist    *tmp;

    if (!lst || !f)
        return (NULL);
    new_lst = ft_lstnewS(NULL);
    tmp = new_lst;
    while (lst)
    {
        tmp->content = (*f)(lst->content);
        if (del)
            (*del)(lst->content);
        if (lst->next)
            tmp->next = ft_lstnewS(NULL);
        tmp = tmp->next;
        lst = lst->next;
    }
    return (new_lst);
}
