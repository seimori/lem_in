/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 18:10:32 by seimori           #+#    #+#             */
/*   Updated: 2020/06/17 15:58:42 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

void				write_rooms_id(SDL_Renderer *renderer, int id, SDL_Rect *rect)
{
	SDL_Surface		*text_surface;
	TTF_Font		*font;
	SDL_Color		text_color = {50, 50, 50};
	char			*text;
	SDL_Texture		*texture;

	font = TTF_OpenFont("Roboto-Light.ttf", 50);
	if (font == NULL)
		sdl_error();
	text = ft_itoa(id);
	text_surface = TTF_RenderText_Solid(font, text, text_color);
	if (text_surface == NULL)
		sdl_error();
	texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	if (texture == NULL)
		sdl_error();
	SDL_RenderCopy(renderer, texture, NULL, rect);
	SDL_RenderPresent(renderer);
}

SDL_Renderer	*set_render_draw_color(SDL_Renderer *renderer, t_room *room, t_in *in)
{
	if (room == in->room)
		SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
	else if (room == in->end_room)
		SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
	else
		SDL_SetRenderDrawColor(renderer, 200, 200, 0, 255);
	return (renderer);
}

void			draw_rooms(SDL_Renderer *renderer, t_in *in, int zoom_multiplier)
{
	t_room		*room;
	SDL_Rect	rect;

	room = in->room;
	rect.w = zoom_multiplier;
	rect.h = zoom_multiplier;
	while (room)
	{
		renderer = set_render_draw_color(renderer, room, in);
		rect.x = room->x * zoom_multiplier;
		rect.y = room->y * zoom_multiplier;
		SDL_RenderFillRect(renderer, &rect);
		write_rooms_id(renderer, room->id, &rect);
		SDL_RenderPresent(renderer);
		room = room->next;
	}
	// SDL_RenderDrawLine(renderer, 10, 200, 300, 400);
}

void				initialize_ttf(void)
{
	if (TTF_Init() < 0)
		{
			ft_printf("SDL_ttf error -> %s\n", TTF_GetError());
			exit(1);
		}
	else
		ft_printf("TTF Initialized!\n");
	
}

void				draw_connections(SDL_Renderer *renderer, t_in *in,
					int zoom_multiplier)
{
	t_room			*room;	
	int				**matrix;
	t_coord			*source;
	t_coord			*destination;

	room = in->room;
	matrix = in->matrix;
	source->x = room->x;
	source->y = room->y;
	destination = get_destination_coord(room, matrix); //TODO: Continue from here. Need to create that function.
}

void				visualizer(t_in *in)
{
	t_game		*game;
	int			zoom_multiplier;

	game = NULL;
	game = initialize_game(game);
	game = game->init(game);
	zoom_multiplier = 50;
	initialize_ttf();
	SDL_SetRenderDrawColor(game->screen->renderer, 50, 50, 50, 255);
	if((SDL_RenderClear(game->screen->renderer)) < 0)
		sdl_error();
	while (game->running)
	{
		game->running = poll_for_quit(game->running);
		draw_rooms(game->screen->renderer, in, zoom_multiplier);
		draw_connections(game->screen->renderer, in, zoom_multiplier);
	}
	game = game->quit(game);
}
