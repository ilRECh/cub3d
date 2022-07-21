/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclearD.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:40:28 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclearD(t_dlist **lst, void (*del)(void *))
{
    t_dlist    *tmp;

    if (!lst)
        return ;
    while (*lst)
    {
        if (del)
            (*del)((*lst)->content);
        tmp = *lst;
        *lst = (*lst)->next;
        free(tmp);
    }
}
