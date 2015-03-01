/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:56:39 by adebray           #+#    #+#             */
/*   Updated: 2015/03/01 05:48:32 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

int			ft_test(int **array)
{
	int		(*f[4])(t_env *);
	t_env	env_tmp;

	f[0] = ft_down;
	f[1] = ft_up;
	f[2] = ft_left;
	f[3] = ft_right;
	env_tmp.array = array;
	env_tmp.score = 0;
	if (!f[0](&env_tmp) && !f[1](&env_tmp)
		&& !f[2](&env_tmp) && !f[3](&env_tmp))
		return (0);
	else
		return (1);
}

int			ft_canplay(t_env *env)
{
	int		**array;
	int		i;
	int		j;
	int		ret;

	i = 0;
	ret = 0;
	array = (int **)malloc(sizeof(int *) * SIZE);
	while (i < SIZE)
	{
		j = 0;
		array[i] = (int *)malloc(sizeof(int) * SIZE);
		while (j < SIZE)
		{
			array[i][j] = env->array[i][j];
			j += 1;
		}
		i += 1;
	}
	ret = ft_test(array);
	i = 0;
	while (i < SIZE)
	{
		free(array[i]);
		i += 1;
	}
	free(array);
	return (ret);
}

int			ft_getkey(t_env *env, int c)
{
	int		(*f[4])(t_env *);

	f[0] = ft_down;
	f[1] = ft_up;
	f[2] = ft_left;
	f[3] = ft_right;
	if (f[c - 258](env))
	{
		if (!(ft_create_number(env)))
			return (0);
		else
			return (1);
	}
	if (ft_check_win(env->array))
		env->win = 2;
	if (!(ft_canplay(env)))
		return (0);
	return (1);
}

int			ft_getch(t_env *env)
{
	int		c;

	c = getch();
	if (env->win == 2)
	{
		if (c == 'y')
			env->win = 1;
		else
			return (0);
	}
	if (c == ESC)
		return (0);
	else if (c == UP || c == DOWN || c == LEFT || c == RIGHT)
		return (ft_getkey(env, c));
	return (1);
}

void		ft_draw(t_env *env)
{
	t_vec4	win;

	win.x = 0;
	win.y = 0;
	win.width = COLS;
	win.height = 5;
	ft_score(&win, env);
	win.width = COLS / SIZE;
	win.height = (LINES - 5) / SIZE;
	while (win.x < SIZE)
	{
		win.y = 0;
		while (win.y < SIZE)
		{
			ft_win(&win, env->array, 5);
			win.y += 1;
		}
		win.x += 1;
	}
}
