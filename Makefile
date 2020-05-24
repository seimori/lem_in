#
#	Variables
#

#	Path of source files
SRC_PATH = sources

#	!!!!!To change!!!!!!
#	List of source files
#	!!!!!!!!!!!!!!!!!!!!
SRC_NAME = lem_in.c get_max_paths.c \
initialize_in.c generate_matrix.c \
get_paths.c pathfinder.c get_next_neighbor.c \
ant_calculus.c \
print_ants.c \
env_to_in.c \
parsing.c parse_fill.c parse_tools.c \
li_free.c ari_get_next_line.c ft_strjoinfree.c \
# get_test_case.c test_case_multi_paths.c \

#	Source full name
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

#	Path of object files
OBJ_PATH = objects

#	Get objects names from source files
OBJ_NAME = $(SRC_NAME:.c=.o)

#	Object full name
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

#	!!!!!To change!!!!
#	Include files path
#	!!!!!!!!!!!!!!!!!!
INC = includes/

#	Include files path flag
CPPFLAGS = -Iincludes

#	Uncomment if you want to compile libft
LIB_PATH = libft

#	Lib file path flag
LDFLAGS = -Llibft

#	-lft represents libft.a
LDLIBS = -lft

#	Compilator
CC = gcc

#	Compilator options
CFLAGS = -g -Werror -Wall -Wextra

#	!!!!!To change!!!!!!
#	Output name
#	!!!!!!!!!!!!!!!!!!!!
NAME = lem-in

#
#	Rules
#

.PHONY: all, clean, fclean, re, norm

all: $(NAME)

#	$^ is $(OBJ)
#	$@ is $(NAME)
# 	Uncomment "@cd $(LIB_PATH) && $(MAKE)" if you want to compile lib
$(NAME): $(OBJ)
	@cd $(LIB_PATH) && $(MAKE)
	$(CC) $^ $(LDFLAGS) $(LDLIBS) -o $@
	$(CC) -g $^ $(LDFLAGS) $(LDLIBS) -o debug

#	2> /dev/null || true is to avoid errors and messages if folder already exists
#	$< is first dependance ($(SRC_PATH)%.c)
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	$(MAKE) -C $(LIB_PATH) clean

fclean: clean
	rm -fv $(NAME) debug
	$(MAKE) -C $(LIB_PATH) fclean

re: fclean all

norm:
	norminette $(SRC)
	norminette $(INC)
