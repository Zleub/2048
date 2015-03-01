/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 01:47:13 by adebray           #+#    #+#             */
/*   Updated: 2015/03/01 02:52:24 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

void		ft_init(void)
{
	initscr();
	cbreak();
	noecho();
	nonl();
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE);
	curs_set(0);
	timeout(80 * 100);
}

int			ft_welcome(t_env *env)
{
	srand((int)time(NULL));
	env->score = 0;
	env->win = 0;
	mvwprintw(stdscr, LINES / 2, COLS / 2 - 15,
		"Welcome to 2048. Press a key.\n");
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
