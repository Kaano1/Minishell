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
	int i;
	t_shell mini;

	i = 0;
	ac = 0;
	av = 0;
	mini.env = clone_env;
	do
	{
		mini.all_line = readline("MiniShell$ ");
		ft_contqoute(&mini);
		ft_pipecheck(&mini);
		ft_pipe_count(&mini);
		ft_parse(&mini);
		//ft_lexer();
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