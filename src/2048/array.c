/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:54:27 by adebray           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/03/01 06:27:19 by adebray          ###   ########.fr       */
=======
/*   Updated: 2015/02/28 17:50:49 by adebray          ###   ########.fr       */
>>>>>>> b931d671db4e2d2bb403367939b1b51c01d67ea7
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

<<<<<<< HEAD
=======
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

>>>>>>> b931d671db4e2d2bb403367939b1b51c01d67ea7
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
