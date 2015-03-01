/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:42:07 by adebray           #+#    #+#             */
/*   Updated: 2015/03/01 01:06:10 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

int		ft_create_number(t_env *env);

// int			ft_moveup(t_env *env, int y, int x, int len)
// {

// }

void		ft_cleancoltop(t_env *env, int y)
{
	int		x;
	int		tmp;

	x = 0;
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
				}
				tmp += 1;
			}
		}
		x += 1;
	}
}

int			ft_coltop(t_env *env, int y)
{
	int		tmp;
	int		x;

	x = 0;
	tmp = -1;
	while (x < SIZE)
	{
		dprintf(2, "%d\n", env->array[x][y]);
		if (tmp != -1 && tmp != x && env->array[x][y] == env->array[tmp][y])
		{
			env->array[tmp][y] += env->array[x][y];
			env->array[x][y] = 0;
		}
		if (env->array[x][y] != 0)
			tmp = x;
		x += 1;
	}
	ft_cleancoltop(env, y);
	return (0);
}

int			ft_up(t_env *env)
{
	int y;

	y = 0;
	while (y < SIZE)
	{
		ft_coltop(env, y);
		y += 1;
	}
	dprintf(2, "UP\n");
	return (1);
}



int			ft_down(t_env *env)
{
	int y;

	y = SIZE;
	while (y >= 0)
	{
		ft_coltop(env, y);
		y -= 1;
	}
	dprintf(2, "DOWN\n");
	return (1);

}

int			ft_right(t_env *env)
{
	(void)env;
	dprintf(2, "RIGHT\n");
	return (1);

}

int			ft_left(t_env *env)
{
	(void)env;
	dprintf(2, "LEFT\n");
	return (1);

}

int			ft_getch(t_env *env)
{
	int		(*f[4])(t_env *);
	int		c;

	(void)env;
	f[0] = ft_down;
	f[1] = ft_up;
	f[2] = ft_left;
	f[3] = ft_right;
	c = getch();
	if (c == ESC)
		return (0);
	else if (c == UP || c == DOWN || c == LEFT || c == RIGHT)
	{
		if (f[c - 258](env))
		{
			if (ft_create_number(env))
				return (1);
			else
				return (0);
		}
	}
	return (1);
}

int			ft_wincheck(void)
{
	int		tmp;
	int		winval;

	tmp = 2;
	winval = WIN_VALUE;
	while (tmp <= winval)
	{
		ft_printf("%d ", tmp);
		if (tmp == winval)
			return (1);
		tmp *= 2;
	}
	return (0);
}

int			ft_random(void)
{
	return (rand() % SIZE);
}

int		ft_check_availability(t_env *env)
{
	int		i;
	int		j;

	j = 0;
	while (j < SIZE)
	{
		i = 0;
		while (i < SIZE)
		{
			if (env->array[j][i] == 0)
				return (1);
			i += 1;
		}
		j += 1;
	}
	return (0);
}

int		ft_create_number(t_env *env)
{
	int		x;
	int		y;

	x = ft_random();
	y = ft_random();
	// dprintf(2, "\n<< [%d][%d] : %d>>", x, y, env->array[x][y]);
	if (env->array[x][y] != 0)
	{
		if (!(ft_check_availability(env)))
			return (0);
		ft_create_number(env);
	}
	else
	{
		if (rand() % 10 == 0)
			env->array[x][y] = 4;
		else
			env->array[x][y] = 2;
	}
	return (1);
}

int			ft_welcome(t_env *env)
{
	srand((int)time(NULL));
	env->score = 0;
	mvwprintw(stdscr, LINES / 2, COLS / 2 - 15, "Welcome to 2048. Press a key.\n");
	wrefresh(stdscr);
	if (getch() == ESC)
	{
		endwin();
		return (0);
	}
	ft_create_number(env);
	ft_create_number(env);
	return (1);
}

int			main(void)
{
	int		i;
	t_env	env;

	if (!(ft_wincheck()))
	{
		ft_printf("Plz, set winval to ^2 number\n");
		return (-1);
	}
	if (!(env.array = ft_new()))
		return (-1);
	ft_init();
	ft_signal();
	ft_welcome(&env);
	i = 0;
	while (42)
	{
		ft_draw(&env);
		if (!(ft_getch(&env)))
			break ;
		i += 1;
	}
	endwin();
	return (0);
}
