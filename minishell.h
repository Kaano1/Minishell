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
	char		**command;
	char		*string;
	char 		**redirect;
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

//Parser/parser_help/add_redirect2.c
char	*ft_redirect(t_shell *mini, int j, int i);
int		redirect_of_string_len(t_shell *mini, int i, int c);
int		ft_redirect_len(char *str);

//Parser/parser_help/add_redirect.c
int		if_while_quotes(char *str, int c);
char	**ft_redirection_add(t_shell *mini, int i);
char	*ft_redirection_clean(t_shell *mini, int i);
char	*pipe_add(char *str, int count, int index);
void	rediretion_cut_add(t_shell *mini);

//Parser/parser_help/add_command.c
int		check_string(char *str, int i);
char	**where_is_command(int index, t_shell *mini, int *catch);

//Parser/find_dollar.c
int		count_null(t_shell *mini, int count_parse);
char	**find_dollar_and_change(t_shell *mini);
char	*get_after_dollar(char *parse, int index);
char	*get_env(char *str, t_shell *mini);
int		check_single_quotes(t_shell *mini, int i, int j, int c_quotes);
char	**check_or_fix_switch(t_shell *mini, int count_parse);

//Parser/switch_to.c
char	*switch_to_parse(char *tmp, int	prs_index, t_shell *mini);
char	*create_switch_to_zero(int i, int j, int prs_index, t_shell *mini);
char	*switch_to_zero(int	prs_index, t_shell *mini);

//Parser/parse.c
void	ft_parse(t_shell *mini);
char	*ft_join_arg(char **mini);
size_t	len_word2(char **s);
void	ft_create_struct(t_shell *mini);

//Parser/ft_mysplit.c
size_t	len_word(char const *s, char c);
char	*mysplit_section(char ***res, char *s, int index, size_t *two_index, int key);
char	*continue_mysplit(char *s, int key);
size_t	if_word_len(char const *s, char c, int key);
char	**ft_mysplit(char *str, char c, int key);

//Parser/building.c
void	ft_building();

//Parser/add_struct.c
char	*ft_add(int row, int column, t_shell *mini);
int		where_is_start(int count_word, char *str);
char	*ft_add_string(t_shell *mini, int index, int start);
void	ft_add_struct(t_shell *mini);

//ft_error.c
void	ft_error(char *str);

//check_main.c
int		ft_space_check(int len, t_shell *mini);
void	ft_pipecheck(t_shell *mini);
void	ft_contqoute(t_shell *mini);

//main.c
void	ft_pipe_count(t_shell *mini);

#endif
