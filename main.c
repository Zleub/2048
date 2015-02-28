/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:42:07 by adebray           #+#    #+#             */
/*   Updated: 2015/02/28 15:23:42 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

void		ft_getch(int **array)
{
	int c = getch();
	dprintf(2, "%d ", c);
	(void)array;
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

int			main(void)
{
	int		**array;

	if (!(ft_wincheck()))
	{
		ft_printf("Plz, set winval to ^2 number\n");
		return (-1);
	}
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
		ft_getch(array);
		ft_draw(array);
		i += 1;
	}

	endwin();
	return (0);
}
