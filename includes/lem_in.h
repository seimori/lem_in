/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:58:18 by seimori           #+#    #+#             */
/*   Updated: 2020/03/16 14:46:31 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
 #define LEM_IN_H

#include "../libft/includes/libft.h"
/*
**  for read and write
*/
#include <unistd.h>
/*
**  for malloc and free
*/
#include <stdlib.h>
/*
**  for perror
*/
#include <stdio.h>
/*
**  for strerror
*/
#include <string.h>
/*
**  for exit
*/
#include <stdlib.h>
/*
**	for open //TODO remove before final push
*/
#include <fcntl.h>

#define FALSE 0
#define TRUE 1

#define VISITED 2
#define LOCKED 3

# define FLAGS O_RDONLY
# define PATHNAME "map"

#define INF 0x7FFFFFFF

# define BUFF_SIZE 500

# define START 1
# define END 2


typedef struct		s_names
{
	int		id;
	int		startend;
	char	*name;
	int		x;
	int		y;
}					t_names;

typedef struct		s_memlist
{
	t_names				*names;
	struct s_memlist	*n;
}					t_memlist;

typedef struct		s_env
{
	int		nb_ants;
	t_names	**names;
	int		**links;
	int		nb_room;
	int		fd;
}					t_env;

typedef struct      s_room
{
	int               id;
	int               x;
	int               y;
	char              *name;
	int               score;
	struct s_room     *next;
	struct s_room     *trail;
	struct s_room     *route;
	int               ants;
}                   t_room;

typedef struct      s_tube
{
	int               in;
	int               out;
	struct s_tube     *next;
}                   t_tube;

typedef struct      s_in
{
	int               ant_size;
	t_tube            *tube;
	t_room            *room;
	t_room            *end_room;
	int               room_count;
	int               **matrix;
	int               max_paths;
}                   t_in;

/*
**  initialize_in.c
*/
t_in            *initialize_in();
// t_room          *create_room_node(int id, int x, int y);
t_room          *create_room_node(t_names *names);
t_tube          *create_tube_node(int in, int out);

/*
**  generate_matrix.c
*/
int             **generate_matrix(t_in *in);

/*
**  get_test_case.c
*/
t_in            *get_test_case();

/*
**	env_to_in.c
*/
t_in			*env_to_in(t_env *e);

/*
**	test_case_multi_paths.c
*/
t_room			*multi_path_rooms(t_in *in);
t_tube			*multi_path_test_tubes(t_in *in);

/*
**  get_max_paths.c
*/
int             get_max_paths(t_in *in);

/*
**  get_paths.c
*/
t_room          **get_paths(t_in *in);

/*
**  pathfinder.c
*/
t_room          *pathfinder(t_in *in);
t_room          *remove_from_queue(t_room *queue, t_room *node);

/*
**  get_next_neighbor.c
*/
t_room          *get_next_neighbor(t_in *in, t_room *node, t_room *neighbor);

/*
**  ant_calculus.c
*/
t_room          **ant_calculus(t_in *in, t_room **paths);

/*
**  print_ants.c
*/
void            print_ants(t_in *in, t_room **paths);

/*
**	parsing.c
*/
t_env			*parsing(char *pathname);

/*
**	parse_tools.c
*/
t_memlist		*li_lstnew();
char			*ft_strcut(char *str, int c, int part);
char			*li_atoi(char *str, int *target, int stop);
int				list_to_tab(t_env *e, t_memlist *mem, int room);

/*
**	parse_fill.c
*/
int				fill_links(t_env *e, char **inst, t_memlist *f, t_memlist *mem);
int				fill_names(char **inst, t_memlist **mem, t_memlist *first);

/*
**	li_free.c
*/
int				error(t_env **e, char **inst, int err);

/*
**	ari_get_next_line.c
*/
int				ari_get_next_line(const int fd, char **line);

/*
**	ft_strjoinfree.c
*/
char			*ft_strjoinfree(char *s1, char *s2, int frees1, int frees2);
#endif