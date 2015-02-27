/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:46:07 by adebray           #+#    #+#             */
/*   Updated: 2015/02/27 23:46:29 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

void		ft_win(t_vec4 *win, int **array, int offset)
{
	WINDOW *caca;

	caca = newwin(win->height, win->width, win->y * win->height + offset, win->x * win->width);
	box(caca, '|', '~');
	mvwprintw(caca, win->height / 2, win->width / 2, "%d", array[win->y][win->x]);
	wrefresh(caca);
}

void		ft_score(t_vec4 *win, int score)
{
	WINDOW *caca;

	caca = newwin(win->height, win->width, win->y * win->height, win->x * win->width);
	box(caca, '|', '~');
	mvwprintw(caca, win->height / 2, win->width / 2, "%d", score);
	wrefresh(caca);
}
