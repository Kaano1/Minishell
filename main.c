#include "minishell.h"

t_shell	mini;

void	ctrl_d(char *input)
{
	if (!input)
	{
		printf("exit\n");
		exit (mini.error);	
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
	mini.error = 0;
	mini.path = NULL;
	mini.parent_pid = getpid();
	mini.env = set_env(env);
	set_paths();
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
		if (*input)
		{
			add_history(input);
			ft_contqoute(input);
			ft_pipecheck(input);
			ft_pipe_count(input);
			mini.all_line = ft_strdup(input);
			ft_parse();
			start_cmd();
		}
		free(input);
	}
	return (0);
}

//redirectionları tanımlayıp siliceğiz
//structa değerlerin gelip gelmediğene bakıcağız
//command kontrolleri yapabiliriz
//builtin yapabiliriz echo, cd, env, pwd, vb...
//executebale mı diye kontrol et
//"$" ve '$' olayını halletmemiz gerekiyor. //OK

//çift tırnak arasındaki '|' ları görmemesi gerekiyor //OK
//command - "echo " "    ahmet" şeklinde veya "echo" "      ahmet" şeklinde gelmiş olabilir. bu durumda hangisi çalışacak bunun ayarlanması gerekiyor.

//flags yapılacak ** şekilde
//kodlarda temizlik yapılıcak.