/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 01:47:13 by adebray           #+#    #+#             */
/*   Updated: 2015/03/01 02:13:57 by adebray          ###   ########.fr       */
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
	timeout(-1);
}

int			ft_welcome(t_env *env)
{
	srand((int)time(NULL));
	env->score = 0;
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
