/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_conf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:01:06 by csamuro           #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_CONF_H
# define SORT_CONF_H

///
/// SAFE LIBFT INCLUDE, DEFINES ARE AFTER
///
# include "libft.h"

///
/// CONFIGURE DEFINES
///
# define INT_

# ifdef CHAR_
#  include "TYPE_CHAR.h"
# else
#  define CHAR_ASSIGN NULL
#  define CHAR_COMPARE NULL
# endif

# ifdef UCHAR_
#  include "TYPE_UCHAR.h"
# else
#  define UCHAR_ASSIGN NULL
#  define UCHAR_COMPARE NULL
# endif

# ifdef INT_
#  include "TYPE_INT.h"
# else
#  define INT_ASSIGN NULL
#  define INT_COMPARE NULL
# endif

# ifdef UINT_
#  include "TYPE_UINT.h"
# else
#  define UINT_ASSIGN NULL
#  define UINT_COMPARE NULL
# endif

# ifdef LONG_
#  include "TYPE_LONG.h"
# else
#  define LONG_ASSIGN NULL
#  define LONG_COMPARE NULL
# endif

# ifdef ULONG_
#  include "TYPE_ULONG.h"
# else
#  define ULONG_ASSIGN NULL
#  define ULONG_COMPARE NULL
# endif

# ifdef FLOAT_
#  include "TYPE_FLOAT.h"
# else
#  define FLOAT_ASSIGN NULL
#  define FLOAT_COMPARE NULL
# endif

# ifdef DOUBLE_
#  include "TYPE_DOUBLE.h"
# else
#  define DOUBLE_ASSIGN NULL
#  define DOUBLE_COMPARE NULL
# endif

static int    function_by_data_type(t_function *function, t_DATA_TYPE type)
{
    if (!function)
        return (1);
    if (type == INT)
        (function->assign = INT_ASSIGN) && (function->compare = INT_COMPARE);
    return (0);
}

#endif