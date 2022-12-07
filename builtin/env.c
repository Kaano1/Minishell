#include "../minishell.h"


int	ft_env(t_shell *mini)
{
    int i;

    i = 0;
    while(mini->env[i])
    {
        put_str_fd(1, mini->env[i]);
        put_str_fd(1, "\n");
        i++;
    }
    return (0);
}


/*int main(int ac, char **av, char **clone_env)
{
    t_shell *mini;
	char	**str;

	ac = 0;
	av = 0;
	
	mini = malloc(sizeof(t_shell));
	mini->first_struct = malloc(sizeof(t_command));
	mini->iter = malloc(sizeof(t_command));
    mini->first_struct->command = malloc(sizeof(char) * 2);
    mini->first_struct->command[0] = ft_strdup("cd");
    mini->env = clone_env;
    mini->first_struct->string = ft_strdup("/Users/kevserkocaaga/Downloads/commit20/builtinkkkk");
    mini->first_struct->redirect = 0;

	ft_env(mini);
}*/