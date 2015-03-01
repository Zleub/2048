/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 01:39:25 by adebray           #+#    #+#             */
/*   Updated: 2015/03/01 03:00:49 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

static int		ft_cleancoltop(t_env *env, int y)
{
	int		ret;
	int		x;
	int		tmp;

	x = 0;
	ret = 0;
	while (x < SIZE)
	{
		if (env->array[x][y] != 0)
		{
			tmp = 0;
			while (tmp < x)
			{
				if (env->array[tmp][y] == 0)
				{
					env->array[tmp][y] = env->array[x][y];
					env->array[x][y] = 0;
					ret += 1;
				}
				tmp += 1;
			}
		}
		x += 1;
	}
	return (ret);
}

static int		ft_coltop(t_env *env, int y)
{
	int		ret;
	int		tmp;
	int		x;

	x = 0;
	tmp = -1;
	ret = 0;
	while (x < SIZE)
	{
		if (tmp != -1 && tmp != x && env->array[x][y] == env->array[tmp][y])
		{
			env->array[tmp][y] += env->array[x][y];
			env->score += env->array[tmp][y];
			env->array[x][y] = 0;
			ret += 1;
		}
		if (env->array[x][y] != 0)
			tmp = x;
		x += 1;
	}
	ret += ft_cleancoltop(env, y);
	return (ret);
}

int				ft_up(t_env *env)
{
	int		ret;
	int		y;

	y = 0;
	ret = 0;
	while (y < SIZE)
	{
		ret += ft_coltop(env, y);
		y += 1;
	}
	return (ret);
}
