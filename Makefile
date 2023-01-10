leaCC	= gcc -g
RM	= rm -rf
NAME	= minishell
LIBFT	= ./Libft/libft.a
CFLGAS	= -g #-fsanitize=address
READLİME = -lreadline -lncurses

SRC	= main.c \
	check_main.c \
	ft_error.c \
	./leparse/ft_mysplit.c \
	./leparse/parser.c \
	./leparse/find_dollar.c \
	./leparse/find_dollar_2.c \
	./leparse/switch_to.c \
	./leparse/add_struct.c \
	./leparse/parser_help/add_command.c \
	./leparse/parser_help/add_redirect.c \
	./leparse/parser_help/add_redirect2.c \
	./builtin/echo.c \
	./builtin/cd.c \
	./builtin/exit.c \
	./builtin/env.c \
	./builtin/builtin_utils/env_len.c \
	./builtin/builtin_utils/is_parent.c \
	./builtin/builtin_utils/is_whitespace.c \
	./builtin/builtin_utils/put_error.c \
	./builtin/builtin_utils/put_str_fd.c \
	./builtin/builtin_utils/put_strnl_fd.c \
	./builtin/pwd.c \
	./builtin/export.c \
	./builtin/unset.c \
	./builtin/builtin.c \
	./cmd/close.c \
	./cmd/cmd.c \
	./cmd/run_cmd.c \
	./redirect/heredoc.c \
	./redirect/input.c \
	./redirect/output.c \
	./redirect/redirect.c \
	./utils/contain.c \
	./utils/set_env.c \
	./utils/set_paths.c \
	./utils/ft_pipe_count.c \
	./utils/just_space.c \
	./utils/control_quotes.c \
	./utils/free_array.c \
	./utils/get_env.c \
	./utils/free_process.c \
	./utils/valid_op.c \
	./utils/ft_strcmp.c \

OBJ = $(SRC:.c=.o)

all : $(LIBFT) $(NAME)
		
$(NAME): $(OBJ)
	$(CC) $(CFLGAS) $(SRC) $(LIBFT) -o $(NAME) $(READLİME) -g

$(LIBFT):
	make -sC ./Libft

clean:
	make clean -sC ./Libft
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: clean all