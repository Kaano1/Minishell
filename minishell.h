#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>
#include "./libft/libft.h"

typedef struct s_shell
{
	char				*all_line;
	char				**parse;
	char				**env;
	struct s_command	*first_struct;
	struct s_command	*iter;
	int					c;
	int					pipe_count;
} t_shell;

typedef struct s_command
{
	char		*command;
	char		*flag;
	char		*string;
	int 		redirect;
	char		*file_name;
	struct s_command	*next;
} t_command;

t_shell mini;
//parse/parse.c
void	ft_parse();
//parse/ft_mysplit.c
char	**ft_mysplit(char *str, char c);
//parse/building.c
void    ft_building();
//main.c
void	ft_contqoute();
//ft_error.c
void	ft_error(char *str);
void 	ft_pipecheck();
void	ft_pipe_count();

#endif