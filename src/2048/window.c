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
	WINDOW	*caca;

	caca = newwin(HEIGHT, WIDTH, Y * HEIGHT + offset, X * WIDTH);
	box(caca, '|', '~');
	if (array[Y][X] > 0)
		mvwprintw(caca, HEIGHT / 2, WIDTH / 2, "%d", array[Y][X]);
	wrefresh(caca);
}

void		ft_score(t_vec4 *win, t_env *env)
{
	WINDOW	*caca;

	caca = newwin(HEIGHT, WIDTH, Y * HEIGHT, X * WIDTH);
	box(caca, '|', '~');
	if (env->win == 2)
		mvwprintw(caca, HEIGHT / 2, WIDTH / 2 - 9,
			"You win with %d points. Continue ?", env->score);
	else if (env->win == 1)
		mvwprintw(caca, HEIGHT / 2, WIDTH / 2 - 9,
			"You win with %d points.", env->score);
	else
		mvwprintw(caca, HEIGHT / 2, WIDTH / 2, "%d", env->score);
	wrefresh(caca);
}
