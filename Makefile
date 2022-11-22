NAME = minishell
SRC = main.c ./Parse/ft_mysplit.c ./Parse/parse.c ft_error.c ./lexer/lexer.c ./libft/libft.a
CC = gcc
LBFT = libft/libft.a
CFLGAS = -Wextra -Werror -Wall 
READLİME = -lreadline
RM = rm -rf
OBJ = $(SRC: .c=.o)

all : $(LBFT) $(NAME)
		
$(NAME): $(OBJ)
	$(CC) $(SRC)  $(CFLGAS) -o $(NAME) $(READLİME)

$(LBFT): 
		make -C libft
clean:
	$(RM) minishell
	make -C ./libft fclean

rec:  clean all
	./minishell
