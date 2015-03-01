/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 01:34:31 by adebray           #+#    #+#             */
/*   Updated: 2015/03/01 02:31:22 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

static int			ft_cleanlinetop(t_env *env, int y)
{
	int		ret;
	int		x;
	int		tmp;

	x = 0;
	ret = 0;
	while (x < SIZE)
	{
		if (env->array[y][x] != 0)
		{
			tmp = 0;
			while (tmp < x)
			{
				if (env->array[y][tmp] == 0)
				{
					env->array[y][tmp] = env->array[y][x];
					env->array[y][x] = 0;
					ret += 1;
				}
				tmp += 1;
			}
		}
		x += 1;
	}
	return (ret);
}

static int			ft_linetop(t_env *env, int y)
{
	int		ret;
	int		tmp;
	int		x;

	x = 0;
	ret = 0;
	tmp = -1;
	while (x < SIZE)
	{
		if (tmp != -1 && tmp != x && env->array[y][x] == env->array[y][tmp])
		{
			env->array[y][tmp] += env->array[y][x];
			env->score += env->array[y][tmp];
			env->array[y][x] = 0;
			ret += 1;
			// x += 1;
		}
		if (env->array[y][x] != 0)
			tmp = x;
		x += 1;
	}
	ret += ft_cleanlinetop(env, y);
	return (ret);
}

int					ft_left(t_env *env)
{
	int ret;
	int y;

	y = 0;
	ret = 0;
	while (y < SIZE)
	{
		ret += ft_linetop(env, y);
		y += 1;
	}
	return (ret);
}
