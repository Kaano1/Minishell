#include "minishell.h"

void	put_char(char *str)
{
	int	i;

	i = 0;
	printf("%s", str);
	while (str[i])
	{
		write(STDOUT_FILENO, &(str[i]), 1);
		i++;
	}
}

int	ft_echo(t_shell *mini)
{
	int	i;
	int	if_flag;

    i = 0;
	if (!mini->first_struct->string)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (0);
    }
	
    while (mini->first_struct->string[i])
	{
        put_char(mini->first_struct->string);
        i = ft_strlen(mini->first_struct->string);
		if (!mini->first_struct->string[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
    if(mini->first_struct->flag[0] != 0)
        write(STDOUT_FILENO, "\n", 1);
    return(0);

}

int main(void)
{
    t_shell *mini;

	mini = malloc(sizeof(t_shell));
	mini->first_struct = malloc(sizeof(t_command));
    mini->first_struct->command = ft_strdup("echo");
    mini->first_struct->string = ft_strdup("neler oluyor hayatta");
    mini->first_struct->flag = 0;
    mini->first_struct->redirect = 0;
    mini->first_struct->file_name = 0;
	ft_echo(mini);
}