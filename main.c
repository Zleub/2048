/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:42:07 by adebray           #+#    #+#             */
/*   Updated: 2015/02/28 15:15:01 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

int			main(void)
{
	int		**array;

	// WIN_VALUE CHECK
	if (!(array = ft_new()))
		return (-1);
	ft_init();
	ft_signal();

	array[0][2] = 10;
	mvwprintw(stdscr, LINES / 2, COLS / 2 - 15, "Welcome to 2048. Press Space.\n");
	wrefresh(stdscr);

	int i = 0;
	while (42)
	{
		timeout(-1);
		int c = getch();
		dprintf(2, "%d ", c);
		ft_draw(array);
		// usleep(800 * 100);
		i += 1;
	}

	endwin();
	return (0);
}
