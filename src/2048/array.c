/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:54:27 by adebray           #+#    #+#             */
/*   Updated: 2015/02/28 17:50:49 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

int			**ft_new(void)
{
	int		i;
	int		**array;

	if (!(array = (int **)malloc(sizeof(int *) * SIZE)))
		return (NULL);
	i = 0;
	while (i < SIZE)
	{
		if (!(array[i] = (int*)malloc(sizeof(int) * SIZE)))
			return (NULL);
		ft_bzero(array[i], sizeof(int) * SIZE);
		i += 1;
	}
	return (array);
}

void		ft_print_array(int fd, int **array)
{
	int		i;
	int		j;

	j = 0;
	while (j < SIZE)
	{
		i = 0;
		while (i < SIZE)
		{
			ft_putnbr_fd(array[i][j], fd);
			i += 1;
		}
		ft_putchar_fd('\n', fd);
		j += 1;
	}
}
