/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:46:07 by adebray           #+#    #+#             */
/*   Updated: 2015/03/01 01:56:39 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

void		ft_win(t_vec4 *win, int **array, int offset)
{
	WINDOW *caca;

	caca = newwin(HEIGHT, WIDTH, Y * HEIGHT + offset, X * WIDTH);
	box(caca, '|', '~');
	if (array[Y][X] > 0)
		mvwprintw(caca, HEIGHT / 2, WIDTH / 2, "%d", array[Y][X]);
	wrefresh(caca);
}

void		ft_score(t_vec4 *win, int score)
{
	WINDOW *caca;

	caca = newwin(HEIGHT, WIDTH, Y * HEIGHT, X * WIDTH);
	box(caca, '|', '~');
	mvwprintw(caca, HEIGHT / 2, WIDTH / 2, "%d", score);
	wrefresh(caca);
}
