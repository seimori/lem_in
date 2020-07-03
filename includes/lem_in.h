/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:58:18 by seimori           #+#    #+#             */
/*   Updated: 2020/07/03 05:07:44 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"

/*
**  for read and write
*/
# include <unistd.h>

/*
**  for malloc and free
*/
# include <stdlib.h>

/*
**  for perror
*/
# include <stdio.h>

/*
**  for strerror
*/
# include <string.h>

/*
**  for exit
*/
# include <stdlib.h>

/*
**	for open //TODO remove before final push
*/
# include <fcntl.h>

# define FALSE 0
# define TRUE 1

# define DUPLICATE 2
# define LOCKED 3

# define NOT_DUPLICATE 0
# define DUPLICATE_IN 1
# define DUPLICATE_OUT 2

# define FLAGS O_RDONLY
# define PATHNAME "map"

# define INF 0x7FFFFFFF

# define BUFF_SIZE 500

# define START 1
# define END 2

typedef struct		s_tube
{
	int				in;
	int				out;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_room
{
	int				id;
	int				x;
	int				y;
	char			*name;
	int				score;
	struct s_room	*next;
	struct s_room	*previous;
	struct s_room	*trail;
	struct s_room	*route;
	int				ants;
	int				duplicate;
}					t_room;

typedef struct		s_in
{
	int				ant_size;
	t_room			*room;
	t_room			*end_room;
	t_tube			*tube;
	int				room_count;
	int				**matrix;
	int				**oriented;
	int				max_paths;
	int				fd;
	char			*map_buf;
	size_t			score_change;
}					t_in;

/*
**  generate_matrix.c
*/
int					**generate_matrix(t_in *in);

/*
**  get_test_case.c
*/
t_in				*get_test_case();

/*
**	test_case_multi_paths.c
*/
t_room				*multi_path_rooms(t_in *in);

/*
**  get_max_paths.c
*/
int					get_max_paths(t_in *in);

/*
**  get_paths.c
*/
t_room				**get_paths(t_in *in);

/*
**	suurballe.c
*/
t_room				**suurballe(t_in *in, t_room **paths);

/*
**  dijkstra.c
*/
t_room				*dijkstra(t_in *in, t_room *path);
t_room				*remove_from_queue(t_room *node);
// t_room				*copy_room_node(t_room *source);

/*
**	bellman_ford.c
*/
t_room				*bellman_ford(t_in *in);

/*
**	node_tools.c
*/
t_room				copy_room_node(t_room *source, t_room copy);

/*
**  get_next_neighbor.c
*/
t_room				*get_next_neighbor(t_in *in, t_room *node,
					t_room *neighbor);

/*
**  ant_calculus.c
*/
t_room				**ant_calculus(t_in *in, t_room **paths);

/*
**  print_ants.c
*/
void				print_ants(t_in *in, t_room **paths);

/*
**	parsing.c
*/
t_in			*parsing(char *pathname);
void			print_links(t_in *e);

/*
**	parse_tools.c
*/
t_room			*li_lstnew(void);
char			*get_name(char *str);
char			*li_atoi(char *str, int *target, int stop);
int				clean_room_list(t_in *e, t_room *mem);
char			*ft_strstopchr(char *s, int c, int stop);

/*
**	parse_fill.c
*/
int				fill_links(t_in *e, char **inst, t_room *mem);
int				fill_names(t_in *e, char **inst, t_room **mem);

/*
**	li_free.c
*/
int				li_free(t_in **e, char **inst, int err);

/*
**	ari_get_next_line.c
*/
int				ari_get_next_line(const int fd, char **line);

/*
**	ft_strjoinfree.c
*/
char			*ft_strjoinfree(char *s1, char *s2, int frees1, int frees2);
#endif
