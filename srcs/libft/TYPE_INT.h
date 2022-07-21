/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TYPE_INT.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:01:17 by csamuro           #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_INT_H
# define TYPE_INT_H

# include <stdlib.h>
# include <unistd.h>

static int    INT_COMPARE(void *A_array,
                       void *B_array, size_t offset_A, size_t offset_B)
{
    int    *A;
    int    *B;

    if (!A_array || !B_array)
        return (write(1, "NULL ARRAY!", 11));
    A = (int *)A_array;
    B = (int *)B_array;
    return (A[offset_A] - B[offset_B]);
}

static int    INT_ASSIGN(void *A_array,
                      void *B_array, size_t offset_A, size_t offset_B)
{
    int    *A;
    int    *B;

    if (!A_array || !B_array)
        return (write(1, "NULL ARRAY!", 11));
    A = (int *)A_array;
    B = (int *)B_array;
    A[offset_A] = B[offset_B];
    return (1);
}

#endif