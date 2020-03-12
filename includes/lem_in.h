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

#define FALSE 0
#define TRUE 1

#define VISITED 2
#define LOCKED 3

#define INF 0x7FFFFFFF

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
t_room          *create_room_node(int id, int x, int y);
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