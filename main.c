#include "minishell.h"

void	ft_contqoute()
{
	int		i;
	int		once;
	int		twice;

	once = 0;
	twice = 0;
	i = 0;
	while (mini.all_line[i])
	{
		if (mini.all_line[i] == 39 && twice == 0)
			once++;
		else if (mini.all_line[i] == 34 && once == 0)
			twice++;
		i++;
		if (once == 2 || twice == 2)
		{
			once = 0;
			twice = 0;
		}
	}
	if (once % 2 != 0 || twice % 2 != 0)
		ft_error("Missing character!");
	add_history(mini.all_line);
}

int main(int ac, char **av, char **clone_env)
{
	int i;

	i = 0;
	ac = 0;
	mini.c = 0;
	av = 0;
	mini.env = clone_env;
	do
	{
		mini.all_line = readline("MiniShell$ ");
		ft_contqoute();
		ft_pipecheck();
		ft_pipe_count();
		ft_parse();
		//ft_lexer();
	} while (mini.all_line != 0);
	return (0);
}


//redirectionları tanımlayıp siliceğiz
//structa değerlerin gelip gelmediğene bakıcağız
//command kontrolleri yapabiliriz
//builtin yapabiliriz echo, cd, env, pwd, vb...
//executebale mı diye kontrol et
//"$" ve '$' olayını halletmemiz gerekiyor.