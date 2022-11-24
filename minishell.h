# ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "./Libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

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

//parse/parse.c
void	ft_parse(t_shell *mini);

//parse/ft_mysplit.c
char	**ft_mysplit(char *str, char c);

//parse/building.c
void    ft_building();

//main.c
void	ft_contqoute(t_shell *mini);

//ft_error.c
void	ft_error(char *str);
void 	ft_pipecheck(t_shell *mini);
void	ft_pipe_count(t_shell *mini);

#endif