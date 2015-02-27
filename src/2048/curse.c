/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:56:39 by adebray           #+#    #+#             */
/*   Updated: 2015/02/27 23:46:31 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

void		ft_init()
{
	initscr();
	cbreak();
	noecho();
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

void		ft_draw(int **array)
{
	t_vec4	win;

	win.x = 0;
	win.y = 0;
	win.width = COLS;
	win.height = 5;
	ft_score(&win, 594);
	win.width = COLS / SIZE;
	win.height = (LINES - 5) / SIZE;
	while (win.x < SIZE)
	{
		win.y = 0;
		while (win.y < SIZE)
		{
			ft_win(&win, array, 5);
			win.y += 1;
		}
		win.x += 1;
	}
}
