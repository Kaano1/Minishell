#include "../minishell.h"

/*void	ft_setenv(char *name, char *value, t_shell *mini)
{
	free(mini->env[i]);
	mini->env[i] = value;
    
}


static void	new_path(void)
{
	char	*value;
    char    *str; 

	value = ft_strdup(getenv("PWD"));
	ft_setenv("OLDPWD", value);
    str = getcwd(str, 0);
	ft_setenv("PWD", str);
	free(value);
}
*/
static void	put_error(char *str)
{
	char	*msg;

	msg = strerror(2);
	put_str_fd(2, "cd: ");
	put_str_fd(2, msg);
	put_str_fd(2, ": ");
	put_str_fd(2, str);
}


int	ft_cd(t_shell *mini)
{
	int		err;
	char	*home;

	if (!mini->first_struct->string)
	{
		home = getenv("HOME");
        chdir(home);
    }
	else
	{
		err = chdir(mini->first_struct->string);
		if (err)
		{
			put_error(mini->first_struct->string);
			return (1);
		}
	}
	return (0);
	//new_path();
}


/*int main(void)
{
    t_shell *mini;
	char	**str;

	
	mini = malloc(sizeof(t_shell));
	mini->first_struct = malloc(sizeof(t_command));
	mini->iter = malloc(sizeof(t_command));
    mini->first_struct->command = malloc(sizeof(char) * 2);
    mini->first_struct->command[0] = ft_strdup("cd");
    mini->first_struct->string = ft_strdup("/Users/kevserkocaaga/Downloads/commit20/builtinkkkk");
    mini->first_struct->redirect = 0;
	ft_cd(mini);
}
*/
