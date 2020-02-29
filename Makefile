#
#	Variables
#

#	Path of source files
SRC_PATH = sources

#	List of source files
SRC_NAME = lem_in.c \

#	Source full name
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

#	Path of object files
OBJ_PATH = objects

#	Get objects names from source files
OBJ_NAME = $(SRC_NAME:.c=.o)

#	Object full name
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

#	Include files path
INC_PATH = includes

#	Include files path flag
CPPFLAGS = -Iincludes

#	Lib file path flag
LDFLAGS = -Llibft

#	-lft represents libft.a
LDLIBS = -lft

#	Output name
NAME = a.out

#	Compilator
CC = gcc

#	Compilator options
CFLAGS = -Werror -Wall -Wextra

#
#	Rules
#

.PHONY: all, clean, fclean, re

all: $(NAME)

#	$^ is $(OBJ)
#	$@ is $(NAME)
$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

#	2> /dev/null || true is to avoid errors and messages if folder already exists
#	$< is first dependance ($(SRC_PATH)%.c)
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

norm:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
