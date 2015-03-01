/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:56:39 by adebray           #+#    #+#             */
/*   Updated: 2015/03/01 02:16:04 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

int			ft_getch(t_env *env)
{
	int		(*f[4])(t_env *);
	int		c;

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

void		ft_resize(int sig)
{
	if (sig != SIGWINCH)
	{
		ft_printf("SIGNAL RECEIVED IN SIGWINCH NOT SIGWINCH\n");
		return ;
	}
	endwin();
	refresh();
	clear();
}

void		ft_signal(void)
{
	signal(SIGWINCH, ft_resize);
}

void		ft_draw(t_env *env)
{
	t_vec4	win;

	win.x = 0;
	win.y = 0;
	win.width = COLS;
	win.height = 5;
	ft_score(&win, env->score);
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
