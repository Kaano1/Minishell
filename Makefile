CC	= gcc -g
RM	= rm -rf
NAME	= minishell
LIBFT	= ./Libft/libft.a
CFLGAS	= -g #-fsanitize=address
READLİME = -lreadline -lncurses

SRC	= main.c \
	check_main.c \
	ft_error.c \
	./Parser/ft_mysplit.c \
	./Parser/parser.c \
	./Parser/find_dollar.c \
	./Parser/switch_to.c \
	./Parser/add_struct.c \
	./Parser/parser_help/add_command.c \
	./Parser/parser_help/add_redirect.c \
	./Parser/parser_help/add_redirect2.c \
	./utils/set_env.c \
	./utils/set_paths.c \
	./utils/ft_pipe_count.c \
	./builtin/echo.c \
	./builtin/cd.c \
	./builtin/exit.c \
	./builtin/env.c \
	./builtin/builtin_utils.c \
	./builtin/builtin_utils_2.c \
	./builtin/pwd.c \
	./builtin/export.c \
	./builtin/unset.c \
	./Lexer/lexer.c 

OBJ = $(SRC:.c=.o)

all : $(LIBFT) $(NAME)
		
$(NAME): $(OBJ)
	$(CC) $(CFLGAS) $(SRC) $(LIBFT) -o $(NAME) $(READLİME)

$(LIBFT):
	make -sC ./Libft

clean:
	make clean -sC ./Libft
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: clean all