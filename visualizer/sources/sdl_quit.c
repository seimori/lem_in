/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 17:28:27 by seimori           #+#    #+#             */
/*   Updated: 2020/06/02 18:07:05 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

t_game			*game_quit(t_game *game)
{
	SDL_DestroyRenderer(game->screen->renderer);
	SDL_DestroyWindow(game->screen->window);
	game->screen->window = NULL;
	game->screen->renderer = NULL;
	SDL_Quit();
	free(game->screen);
	free(game);
	return (game);
}

int				poll_for_quit(int running)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			running = SDL_FALSE;
	}
	return (running);
}
