/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:47:39 by adebray           #+#    #+#             */
/*   Updated: 2015/03/01 00:47:07 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <time.h>
# include <curses.h>
# include <libft.h>
# include <ft_printf.h>

typedef struct s_env	t_env;

struct					s_env
{
	int					**array;
	int					score;
};

typedef struct s_vec4	t_vec4;

struct		s_vec4
{
	int		x;
	int		y;
	int		width;
	int		height;
};

enum		e_const
{
			SIZE = 10,
			WIN_VALUE = 2048,
			ESC = 27,
			UP = 259,
			LEFT = 260,
			RIGHT = 261,
			DOWN = 258
};

/*
** curse.c
*/

void		ft_init();
void		ft_resize(int sig);
void		ft_signal(void);
void		ft_draw(t_env *env);

/*
** array.c
*/

int			**ft_new(void);
void		ft_print_array(int fd, int **array);

/*
** window.c
*/

void		ft_win(t_vec4 *win, int **array, int offset);
void		ft_score(t_vec4 *win, int score);

#endif
