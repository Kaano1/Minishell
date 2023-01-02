#include "minishell.h"

t_shell	mini;

void	ctrl_d(char *input)
{
	if (!input)
	{
		printf("exit\n");
		exit (errno);	
	}
}

void	ctrl_c(int sig)
{
	(void)sig;
	mini.ignore = TRUE;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	write(1, "\033[A", 3);
}

void	init_app(char **env)
{
	errno = 0;
	mini.path = NULL;
	mini.parent_pid = getpid();
	mini.env = set_env(env);
	set_paths();
}

void	continue_main(char *input)
{
	if (*input && !just_space(input))
	{
		add_history(input);
		if (ft_pipecheck(input) && ft_contqoute(input) && control_quotes(input))
		{
			ft_pipe_count(input);
			mini.all_line = ft_strdup(input);
			ft_parse();
			start_cmd();
		}
	}
}

int main(int ac, char **av, char **clone_env)
{
	char	*input;

	init_app(clone_env);
	while (av && ac)
	{
		mini.ignore = FALSE;
		signal(SIGINT, &ctrl_c);
		signal(SIGQUIT, SIG_IGN);
		write(1, "\033[32m", 5);
		input = readline("MiniShell$ ");
		write(1, "\033[0m", 4);
		ctrl_d(input);
		if (mini.ignore)
		{
			free(input);
			input = malloc(1);
		}
		continue_main(input);
		free(input);
	}
	return (0);
}
