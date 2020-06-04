/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 08:04:15 by seimori           #+#    #+#             */
/*   Updated: 2020/06/02 19:16:54 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H 
# define VISUALIZER_H

# include <stdlib.h>
# include <unistd.h>
# define SDL_MAIN_HANDLED
# include <SDL2/SDL.h>
// # include "../../libft/includes/libft.h"
# include "../../includes/lem_in.h"

# define SCREEN_W 640
# define SCREEN_H 480
# define SCREEN_SCALE 1
# define SCREEN_NAME "Protoype"

typedef struct		s_screen
{
	unsigned int	w;
	unsigned int	h;
	const char		*name;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}					t_screen;

typedef struct		s_game
{
	SDL_bool		running;
	struct s_game	*(*init)(struct s_game *);
	struct s_game	*(*quit)(struct s_game *);
	t_screen		*screen;
}					t_game;

t_game				*initialize_game(t_game *game);
int					poll_for_quit(int running);
t_game				*game_quit(t_game *game);
void				visualizer(t_in *in);

#endif
