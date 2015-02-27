/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:42:07 by adebray           #+#    #+#             */
/*   Updated: 2015/02/27 22:57:15 by adebray          ###   ########.fr       */
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

	int i = 0;
	while (42)
	{
		ft_draw(array);
		// ft_printf("%d\n", i);
		usleep(800 * 100);
		i += 1;
	}

	endwin();
	return (0);
}
