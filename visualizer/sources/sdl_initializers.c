/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_initializers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 17:24:22 by seimori           #+#    #+#             */
/*   Updated: 2020/06/02 18:08:15 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

t_screen		*initialize_screen(t_screen *screen)
{
	screen = (t_screen*)ft_memalloc(sizeof(t_screen));
	screen->w = SCREEN_SCALE * SCREEN_W;
	screen->h = SCREEN_SCALE * SCREEN_H;
	screen->name = SCREEN_NAME;
	screen->window = NULL;
	screen->renderer = NULL;
	return (screen);
}

void			initialize_window(t_screen *screen)
{
	screen->window = SDL_CreateWindow(
		screen->name,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		screen->w,
		screen->h,
		0
	);
}

void			initialize_renderer(t_screen *screen)
{
	screen->renderer = SDL_CreateRenderer(
		screen->window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
}

t_game			*game_init(t_game *game)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		ft_printf("SDL error -> %s\n", SDL_GetError());
		exit(1);
	}
	initialize_window(game->screen);
	initialize_renderer(game->screen);
	game->running = SDL_TRUE;
	return (game);
}

t_game			*initialize_game(t_game *game)
{
	game = (t_game*)ft_memalloc(sizeof(t_game));
	game->running = SDL_FALSE;
	game->init = game_init;
	game->quit = game_quit;
	game->screen = initialize_screen(game->screen);
	return (game);
}
