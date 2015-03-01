/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:54:27 by adebray           #+#    #+#             */
/*   Updated: 2015/03/01 06:27:19 by adebray          ###   ########.fr       */
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

int			ft_check_win(int **array)
{
	int i;
	int j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (array[i][j] >= WIN_VALUE)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
