/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extra_regions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 23:44:53 by name              #+#    #+#             */
/*   Updated: 2021/10/03 15:38:48 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_any
{
	int	x;
	int	y;
}	t_any;

typedef enum e_mode
{
	encrypt,
	decrypt
}	t_mode;

static inline bool	check_symbol(t_mode mode, int y, int x, t_all *all)
{
	if (all->map[y][x] == ' ')
		return (true);
	else if (mode == encrypt)
	{
		if (all->map[y][x] == 'A' || all->map[y][x] == 'B'
			|| all->map[y][x] == 'Z')
			return (true);
	}
	else if (mode == decrypt)
	{
		if (all->map[y][x] == '0' || all->map[y][x] == '1'
			|| all->map[y][x] == all->plrpos.direction)
			return (true);
	}
	return (false);
}

static void	proceed(t_mode mode, int y, int x, t_all *all)
{
	if (check_symbol(mode, y, x, all))
		return ;
	else if (mode == encrypt)
		all->map[y][x] = 'A' * (all->map[y][x] == '0') 
			+ 'B' * (all->map[y][x] == '1') 
			+ 'Z' * (all->map[y][x] == all->plrpos.direction);
	else if (mode == decrypt)
		all->map[y][x] = '0' * (all->map[y][x] == 'A') 
			+ '1' * (all->map[y][x] == 'B') 
			+ all->plrpos.direction * (all->map[y][x] == 'Z');
	proceed(mode, y - 1, x, all);
	proceed(mode, y - 1, x - 1, all);
	proceed(mode, y, x - 1, all);
	proceed(mode, y + 1, x - 1, all);
	proceed(mode, y + 1, x, all);
	proceed(mode, y + 1, x + 1, all);
	proceed(mode, y, x + 1, all);
	proceed(mode, y - 1, x + 1, all);
}

static bool	find_any(t_any *any, t_all *all, t_mode mode)
{
	any->y = -1;
	while (all->map[++any->y])
	{
		any->x = -1;
		while (all->map[any->y][++any->x])
		{
			if (mode == encrypt && all->map[any->y][any->x] == '0')
				return (true);
			else if (mode == decrypt && all->map[any->y][any->x] == 'A')
				return (true);
		}
	}
	return (false);
}

//'0' == 'A'
//'1' == 'B'
//all->plrpos.direction == 'Z'

bool	check_extra_regions(t_all *all)
{
	t_any	any;

	find_any(&any, all, encrypt);
	proceed(encrypt, any.y, any.x, all);
#ifdef DEBUG
{
	for (int i = 0; all->map[i]; i++)
	{
		printf("|%s|\n", all->map[i]);
	}
}
#endif
	if (find_any(&any, all, encrypt))
		return (true);
	find_any(&any, all, decrypt);
	proceed(decrypt, any.y, any.x, all);
	#ifdef DEBUG
{
	for (int i = 0; all->map[i]; i++)
	{
		printf("|%s|\n", all->map[i]);
	}
}
#endif
return (false);
}
