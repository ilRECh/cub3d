/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:08:54 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void    write_out(unsigned int n, int fd)
{
    char    chr;

    chr = 0;
    if (n < 10)
    {
        chr = '0' + n;
        write(fd, &chr, 1);
        return ;
    }
    write_out(n / 10, fd);
    write_out(n % 10, fd);
}

void    ft_putnbr_fd(int n, int fd)
{
    unsigned int    u_n;

    if (n < 0)
        write(fd, "-", 1);
    u_n = ft_abs(n);
    write_out(u_n, fd);
}
