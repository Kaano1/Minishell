# ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <sys/ioctl.h>

# define TRUE 1
# define FALSE 0

typedef struct s_command
{
	pid_t		pid;
	int			fd[2];
	char		**command;
	char		*string;
	char 		**redirect;
	struct s_command	*next;
} t_command;

typedef struct s_shell
{
	int					parent_pid;
	int					ignore;
	char				*all_line;
	char				**parse;
	char				**check_parser;
	char				**env;
	struct s_command	*first_struct;
	struct s_command	*iter;
	char				**path;
	int					error;
	int					pipe_count;
} t_shell;

extern t_shell	mini;

//Parser/parser_help/add_redirect2.c
char	*ft_redirect(char **parse, int j, int i);
int		redirect_of_string_len(char **parse, int i, int c);
int		ft_redirect_len(char *str);

//Parser/parser_help/add_redirect.c
int		if_while_quotes(char *str, int c);
void	ft_redirection_add(char **parse, int i);
void	ft_redirection_clean(int i);
char	*pipe_add(char *str, int count, int index);
void	rediretion_cut_add(void);

//Parser/parser_help/add_command.c
int		check_string(char *str, int i);
void	where_is_command(int index, int *catch);

//Parser/find_dollar.c
int		count_null(char **parse, int count_parse);
char	**find_dollar_and_change(void);
char	*get_after_dollar(char *parse, int index);
char	*get_env(char *str);
int		check_single_quotes(int i, int j, int c_quotes);
char	**check_or_fix_switch(int count_parse);

//Parser/switch_to.c
char	*switch_to_parse(char *tmp, int	prs_index);
char	*create_switch_to_zero(int i, int j, int prs_index);
char	*switch_to_zero(int	prs_index);

//Parser/parse.c
void	ft_parse(void);
char	*ft_join_arg(char **mini);
size_t	len_word2(char **s);
void	ft_create_struct(void);

//Parser/ft_mysplit.c
size_t	len_word(char const *s, char c);
char	*mysplit_section(char ***res, char *s, int index, size_t *two_index, int key);
char	*continue_mysplit(char *s, int key);
size_t	if_word_len(char const *s, char c, int key);
char	**ft_mysplit(char *str, char c, int key);

//Parser/building.c
void	ft_building();

//Parser/add_struct.c
char	*ft_add(int row, int column, char **parse, int key);
int		where_is_start(int count_word, char *str);
char	*ft_add_string(int index, int start);
void	ft_add_struct(void);

//ft_error.c
void	ft_error(char *str);

//check_main.c
int		ft_space_check(int len, char *str);
void	ft_pipecheck(char *str);
void	ft_contqoute(char *str);

//main.c
void	init_app(char **env);
int		main(int ac, char **av, char **clone_env);

//builtin
int	ft_cd(void);
int	ft_echo(void);
int	ft_exit(void);
int	ft_env(void);
static void	put_error(char *str);
void	put_str_fd(int fd, char *str);
void	put_strnl_fd(int fd, char *str);
void	ft_pwd(void);
void	ft_export(void);
void	ft_unset(void);
int		is_whitespace(char c);
void	free_array(char **arr);
void	set_paths(void);
int		env_len(void);

//lexer
void    ft_lexer(t_shell *mini);

//utils
void	ft_pipe_count(char *str);
char	**set_env(char **env);
void	set_paths();

#endif
