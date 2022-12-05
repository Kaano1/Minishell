CC	= gcc
RM	= rm -rf
NAME	= minishell
LIBFT	= ./Libft/libft.a
CFLGAS	= #-Wextra -Werror -Wall
READLİME = -lreadline -lncurses

SRC	= main.c \
	check_main.c \
	ft_error.c \
	./Lexer/lexer.c \
	./Parser/ft_mysplit.c \
	./Parser/parser.c \
	./Parser/find_dollar.c \
	./Parser/switch_to.c \
	./Parser/add_struct.c \
	./Parser/parser_help/add_command.c \
	./Parser/parser_help/add_flags.c \
	./Parser/parser_help/add_string.c \
	./Parser/parser_help/add_redirect.c

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