/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 18:10:32 by seimori           #+#    #+#             */
/*   Updated: 2020/06/04 16:18:52 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

void			draw(SDL_Renderer *renderer, t_in *in)
{
	SDL_Rect	rect;
	int			zoom_multiplier;

	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	zoom_multiplier = 50;
	rect.w = zoom_multiplier;
	rect.h = zoom_multiplier;
	while (in->room)
	{
		rect.x = in->room->x * zoom_multiplier;
		rect.y = in->room->y * zoom_multiplier;
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
		in->room = in->room->next;
	}
	// SDL_RenderDrawLine(renderer, 10, 200, 300, 400);
}

void				visualizer(t_in *in)
{
	t_game		*game;

	game = NULL;
	game = initialize_game(game);
	game = game->init(game);
	while (game->running)
	{
		game->running = poll_for_quit(game->running);
		SDL_SetRenderDrawColor(game->screen->renderer, 50, 50, 50, 255);
		SDL_RenderClear(game->screen->renderer);
		draw(game->screen->renderer, in);
		// SDL_RenderPresent(game->screen->renderer);
	}
	game = game->quit(game);
}

// int			main(void)
// {
// 	char	*line;

// 	ft_printf("We're on sdl.c 01\n");
// 	while (get_next_line(STDIN_FILENO, &line) > 0)
// 	{
// 		ft_printf("%s\n", line);
// 		ft_strdel(&line);
// 	}
// 	ft_strdel(&line);
// 	ft_printf("We're on sdl.c 02\n");
// 	return (0);
// }