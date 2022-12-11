#include "minishell.h"

void	ft_pipe_count(t_shell *mini) //pipe sayimizi tutuyor ileride pipe counta gore struct ve fork yapicaz.
{
	int i;

	i = 0;
	while (mini->all_line[i])
	{
		if (mini->all_line[i] == '|')
			mini->pipe_count++;
		i++;
	}
}

int main(int ac, char **av, char **clone_env)
{
	char	*input;
	int i;
	t_shell mini;

	i = 0;
	ac = 0;
	av = 0;
	mini.env = clone_env;
	mini.parent_pid = getpid();
	do
	{
		write(1, "\033[33m", 5);
		input = readline("MiniShell$ ");
		write(1, "\033[0m", 4);
		if (*input)
		{
			mini.all_line = ft_strdup(input);
			ft_contqoute(&mini);
			ft_pipecheck(&mini);
			ft_pipe_count(&mini);
			ft_parse(&mini);
			printf("%s\n", mini.first_struct->string);
			//ft_lexer(&mini);
		}
		free(input);
	} while (mini.all_line != 0);
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