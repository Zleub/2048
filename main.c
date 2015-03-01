/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:42:07 by adebray           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/03/01 06:28:10 by adebray          ###   ########.fr       */
=======
/*   Updated: 2015/03/01 03:37:33 by adebray          ###   ########.fr       */
>>>>>>> b931d671db4e2d2bb403367939b1b51c01d67ea7
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

<<<<<<< HEAD
static int	ft_wincheck(void)
=======
int			ft_wincheck(void)
>>>>>>> b931d671db4e2d2bb403367939b1b51c01d67ea7
{
	int		tmp;
	int		winval;

	tmp = 2;
	winval = WIN_VALUE;
	while (tmp <= winval)
	{
		if (tmp == winval)
			return (1);
		tmp *= 2;
	}
	return (0);
}

<<<<<<< HEAD
static int	ft_random(void)
=======
int			ft_random(void)
>>>>>>> b931d671db4e2d2bb403367939b1b51c01d67ea7
{
	return (rand() % SIZE);
}

<<<<<<< HEAD
static int	ft_check_availability(t_env *env)
=======
int			ft_check_availability(t_env *env)
>>>>>>> b931d671db4e2d2bb403367939b1b51c01d67ea7
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

int			ft_create_number(t_env *env)
{
	int		x;
	int		y;

	x = ft_random();
	y = ft_random();
	if (env->array[x][y] != 0)
	{
		if (!(ft_check_availability(env)))
			return (0);
		return (ft_create_number(env));
	}
	else
	{
		if (rand() % 10 == 0)
			env->array[x][y] = 4;
		else
			env->array[x][y] = 2;
		return (1);
	}
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
	signal(SIGWINCH, ft_resize);
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
	ft_printf("You scored %d\n", env.score);
	return (0);
}
