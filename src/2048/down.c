/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 01:37:35 by adebray           #+#    #+#             */
/*   Updated: 2015/03/01 02:30:33 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

static int		ft_cleancoldown(t_env *env, int y)
{
	int		ret;
	int		x;
	int		tmp;

	ret = 0;
	x = SIZE - 1;
	while (x >= 0)
	{
		if (env->array[x][y] != 0)
		{
			tmp = SIZE - 1;
			while (tmp > x)
			{
				if (env->array[tmp][y] == 0)
				{
					env->array[tmp][y] = env->array[x][y];
					env->array[x][y] = 0;
					ret += 1;
				}
				tmp -= 1;
			}
		}
		x -= 1;
	}
	return (ret);
}

static int		ft_coldown(t_env *env, int y)
{
	int		ret;
	int		tmp;
	int		x;

	ret = 0;
	x = SIZE - 1;
	tmp = -1;
	while (x >= 0)
	{
		if (tmp != -1 && tmp != x && env->array[x][y] == env->array[tmp][y])
		{
			env->array[tmp][y] += env->array[x][y];
			env->score += env->array[tmp][y];
			env->array[x][y] = 0;
			ret += 1;
			// x -= 1;
		}
		if (env->array[x][y] != 0)
			tmp = x;
		x -= 1;
	}
	ret += ft_cleancoldown(env, y);
	return (ret);
}

int				ft_down(t_env *env)
{
	int		ret;
	int		y;

	ret = 0;
	y = SIZE - 1;
	while (y >= 0)
	{
		ret += ft_coldown(env, y);
		y -= 1;
	}
	return (ret);
}
