#
#	Variables
#

#	Path of source files
LIBFT_SRC_PATH = sources
GNL_SRC_PATH = sources/get_next_line
PRINTF_SRC_PATH = sources/printf

#	!!!!!To change!!!!!!
#	List of source files
#	!!!!!!!!!!!!!!!!!!!!

LIBFT_SRC_NAME = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		   ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		   ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
		   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		   ft_toupper.c ft_tolower.c \
		   ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		   ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		   ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		   ft_strsplit_spaces.c \
		   ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		   ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		   ft_lstmap.c \
		   ft_isspace.c ft_isupper.c ft_islower.c ft_strtolower.c ft_strtoupper.c \
		   ft_issign.c \
		   ft_strmap_uc.c ft_strrev.c ft_strndup.c \

GNL_SRC_NAME = get_next_line.c \

PRINTF_SRC_NAME = printf.c print_arg.c \
		   tools.c fillers.c identifiers.c get_typeindex.c \
		   print_int.c print_float.c print_csp.c \
		   print_numbers.c print_numbers_signed.c \
		   print_options.c print_options_fpn.c \
		   initializers.c  print_width_string.c \
		   print_percent.c print_precision.c \
		   print_sign_and_hash.c print_float_tools.c \
		   extra.c \

#	Source full name
SRC = $(addprefix $(LIBFT_SRC_PATH)/, $(LIBFT_SRC_NAME))
SRC += $(addprefix $(GNL_SRC_PATH)/, $(GNL_SRC_NAME))
SRC += $(addprefix $(PRINTF_SRC_PATH)/, $(PRINTF_SRC_NAME))

#	Path of object files
OBJ_PATH = objects

#	Get objects names from source files
OBJ_NAME = $(LIBFT_SRC_NAME:.c=.o)
OBJ_NAME += $(GNL_SRC_NAME:.c=.o)
OBJ_NAME += $(PRINTF_SRC_NAME:.c=.o)

#	Object full name
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

#	!!!!!To change!!!!
#	Include files path
#	!!!!!!!!!!!!!!!!!!

INC = includes/libft.h

#	Include files path
INC_PATH = includes

#	Include files path flag
CPPFLAGS = -Iincludes

#	Uncomment if you want to compile libft
#LIB_PATH = libft

#	Lib file path flag
#LDFLAGS = -Llibft

#	-lft represents libft.a
#LDLIBS = -lft

#	!!!!!To change!!!!!!
#	Output name
#	!!!!!!!!!!!!!!!!!!!!
#NAME = a.out
NAME = libft.a

#	Compilator
CC = gcc

#	Compilator options
CFLAGS = -Werror -Wall -Wextra

#
#	Rules
#

.PHONY: all, clean, fclean, re, norm

all: $(NAME)

#	$^ is $(OBJ)
#	$@ is $(NAME)
# 	Uncomment "@cd $(LIB_PATH) && $(MAKE)" if you want to compile lib
$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

#	2> /dev/null || true is to avoid errors and messages if folder already exists
#	$< is first dependance ($(SRC_PATH)%.c)
$(OBJ_PATH)/%.o: $(LIBFT_SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o: $(GNL_SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o: $(PRINTF_SRC_PATH)/%.c
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
	norminette $(INC)
