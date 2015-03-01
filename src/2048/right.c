/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 01:35:23 by adebray           #+#    #+#             */
/*   Updated: 2015/03/01 02:31:22 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

static int		ft_cleanlinedown(t_env *env, int y)
{
	int		ret;
	int		x;
	int		tmp;

	x = SIZE - 1;
	ret = 0;
	while (x >= 0)
	{
		if (env->array[y][x] != 0)
		{
			tmp = SIZE - 1;
			while (tmp > x)
			{
				if (env->array[y][tmp] == 0)
				{
					env->array[y][tmp] = env->array[y][x];
					env->array[y][x] = 0;
					ret += 1;
				}
				tmp -= 1;
			}
		}
		x -= 1;
	}
	return (ret);
}

static int		ft_linedown(t_env *env, int y)
{
	int		ret;
	int		tmp;
	int		x;

	x = SIZE - 1;
	tmp = -1;
	ret = 0;
	while (x >= 0)
	{
		if (tmp != -1 && tmp != x && env->array[y][x] == env->array[y][tmp])
		{
			env->array[y][tmp] += env->array[y][x];
			env->score += env->array[y][tmp];
			env->array[y][x] = 0;
			ret += 1;
			// x -= 1;
		}
		if (env->array[y][x] != 0)
			tmp = x;
		x -= 1;
	}
	ret += ft_cleanlinedown(env, y);
	return (ret);
}

int				ft_right(t_env *env)
{
	int		ret;
	int		y;

	y = SIZE - 1;
	ret = 0;
	while (y >= 0)
	{
		ret += ft_linedown(env, y);
		y -= 1;
	}
	return (ret);
}
