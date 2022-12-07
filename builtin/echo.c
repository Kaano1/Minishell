#include "../minishell.h"

void	put_str(char *str, int i)
{
	while (str[i])
	{
		write(1, &(str[i]), 1);
		i++;
	}
}
// -n flag varsa index yoksa 0 döndürür
// command[1][i] 
// ----- kontrolü yap

int	ft_echo_flag_check(t_shell *mini)
{
	int i;
	int is_nflag;

	i = 0;
	is_nflag = 0;
	while(mini->first_struct->string[i] == '-' || mini->first_struct->string[i] == ' ')
	{
		if((mini->first_struct->string[i] == '-') && (mini->first_struct->string[i + 1] == 'n'))
		{
			i++;
			while(mini->first_struct->string[i] == 'n' && mini->first_struct->string[i + 1] == 'n')
				i++;
			is_nflag = 1;
		}
		i++;
	}
	if(!is_nflag)
		return(0);
	return(i);
}

int	ft_echo(t_shell *mini)
{
	int	i;

    i = ft_echo_flag_check(mini);
	if (!mini->first_struct->string[i])
	{
		write(1, "\n", 1);
		return (0);
    }
	put_str(mini->first_struct->string, i);
    i = ft_echo_flag_check(mini);
    if(i)
        write(1, "\n", 1);
    return(0);

}
/*
int main(int ac, char **av, char **clone_env)
{
    t_shell *mini;
	char	**str;

	ac = 0;
	av = 0;
	
	mini = malloc(sizeof(t_shell));
	mini->first_struct = malloc(sizeof(t_command));
	mini->iter = malloc(sizeof(t_command));
    mini->first_struct->command = malloc(sizeof(char) * 2);
    mini->first_struct->command[0] = ft_strdup("echo");
    mini->env = clone_env;
    mini->first_struct->string = ft_strdup("-annnnnc ---d kevser");
    mini->first_struct->redirect = 0;
	ft_echo(mini);
	printf("kaaaaaan");
}
*/
