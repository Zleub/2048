/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:47:39 by adebray           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/03/01 06:28:29 by adebray          ###   ########.fr       */
=======
/*   Updated: 2015/03/01 03:28:11 by adebray          ###   ########.fr       */
>>>>>>> b931d671db4e2d2bb403367939b1b51c01d67ea7
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# define WIDTH win->width
# define HEIGHT win->height
# define X win->x
# define Y win->y

# include <time.h>
# include <curses.h>
# include <libft.h>
# include <ft_printf.h>

typedef struct s_env	t_env;

struct					s_env
{
	int					**array;
	int					score;
	int					win;
};

typedef struct s_vec4	t_vec4;

struct					s_vec4
{
	int					x;
	int					y;
	int					width;
	int					height;
};

enum					e_const
{
<<<<<<< HEAD
	SIZE = 20,
=======
	SIZE = 4,
>>>>>>> b931d671db4e2d2bb403367939b1b51c01d67ea7
	WIN_VALUE = 2048,
	ESC = 27,
	UP = 259,
	LEFT = 260,
	RIGHT = 261,
	DOWN = 258
};

int						ft_left(t_env *env);
int						ft_up(t_env *env);
int						ft_down(t_env *env);
int						ft_right(t_env *env);
int						ft_create_number(t_env *env);
<<<<<<< HEAD
=======
int						ft_check_availability(t_env *env);
>>>>>>> b931d671db4e2d2bb403367939b1b51c01d67ea7

/*
** init.c
*/

void					ft_init(void);
int						ft_welcome(t_env *env);
<<<<<<< HEAD
void					ft_resize(int sig);
=======
>>>>>>> b931d671db4e2d2bb403367939b1b51c01d67ea7

/*
** curse.c
*/

int						ft_getch(t_env *env);
<<<<<<< HEAD
=======
void					ft_resize(int sig);
>>>>>>> b931d671db4e2d2bb403367939b1b51c01d67ea7
void					ft_draw(t_env *env);

/*
** array.c
*/

int						**ft_new(void);
<<<<<<< HEAD
=======
void					ft_print_array(int fd, int **array);
>>>>>>> b931d671db4e2d2bb403367939b1b51c01d67ea7
int						ft_check_win(int **array);

/*
** window.c
*/

void					ft_win(t_vec4 *win, int **array, int offset);
void					ft_score(t_vec4 *win, t_env *env);

#endif
