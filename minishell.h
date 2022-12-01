# ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_command
{
	char		*command;
	char		**flag;
	char		*string;
	int 		redirect; 
	char		*file_name;
	struct s_command	*next;
} t_command;

typedef struct s_shell
{
	char				*all_line;
	char				**parse;
	char				**check_parser;
	char				**env;
	struct s_command	*first_struct;
	struct s_command	*iter;
	int					c;
	int					pipe_count;
} t_shell;

//Parser/parser_help/add_flags.c
char	**ft_flags_add(t_shell *mini, int index);
int	where_start_to_checkparser(t_shell *mini, int index);
int		flags_check(int	i, t_shell *mini);

//Parser/parser_help/add_command.c
int where_is_command(int index, t_shell *mini);
int	get_string_start(char *str, int c_pipe);

//Parser/find_dollar.c
char	**find_dollar_and_change(t_shell *mini);
char	*get_after_dollar_osman(char *parse, int index);
char	*get_env_osman(char *str, t_shell *mini);
char	**check_or_fix_switch(t_shell *mini, int count_parse);

//Parser/switch_to.c
char	*switch_to_parse(char *tmp, int	prs_index, t_shell *mini);
char	*create_switch_to_zero(int i, int j, int prs_index, t_shell *mini);
char	*switch_to_zero(int	prs_index, t_shell *mini);

//Parser/parse.c
void	ft_parse(t_shell *mini);

//Parser/ft_mysplit.c
char	**ft_mysplit(char *str, char c, int key);

//Parser/building.c
void    ft_building();

//Parser/add_struct.c
void	ft_add_struct(t_shell *mini);

//main.c
void	ft_contqoute(t_shell *mini);

//ft_error.c
void	ft_error(char *str);
void 	ft_pipecheck(t_shell *mini);
void	ft_pipe_count(t_shell *mini);

#endif