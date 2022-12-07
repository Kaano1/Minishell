#include "../minishell.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	set_paths(t_shell *mini)
{
	char	*path;

	if (mini->paths)
		free_array(mini->paths);
	path = get_env("PATH", mini);
	if (!(*path))
		mini->paths = NULL;
	else
		mini->paths = ft_mysplit(path, ':', 1);
	free(path);
}


int	env_len(t_shell *mini)
{
	char	**env;

	env = mini->env;
	while (*env)
		env++;
	return (env - mini->env);
}

int	check_env(char *str)
{
	char	*head;

	head = ft_strchr(str, '=');
	if (!head)
		return (0);
	if (head == str)
		return (0);
	while (*str)
	{
		if (is_whitespace(*str))
			return (0);
		str++;
	}
	return (1);
}

void	add_env(char *str, t_shell *mini)
{
	int		i;
	char	**env;
	char	**new_env;

	i = 0;
	env = mini->env;
	new_env = ft_calloc(sizeof(char **), env_len(mini) + 2);
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = ft_strdup(str);
	free_array(mini->env);
	mini->env= new_env;
}

int	is_include(char *str, t_shell *mini)
{
	int		i;
	int		j;
	char	**env;

	i = 0;
	env = mini->env;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && str[j])
		{
			if (str[j] == '=' && env[i][j] == '=')
				return (i);
			if (str[j] != env[i][j])
				break ;
			j++;
		}
		i++;
	}
	return (-1);
}

void	ft_export(t_shell *mini)
{
	int		pos;
	char	*tmp;
    int i;

    i = 0;
    while (mini->first_struct->string[i])
	{
		if (check_env(mini->first_struct->string))
		{
			pos = is_include(mini->first_struct->string, mini);
			if (pos != -1)
			{
				tmp = mini->env[pos];
				mini->env[pos] = ft_strdup(mini->first_struct->string);
				free(tmp);
			}
			else
				add_env(mini->first_struct->string, mini);
		}
		mini->first_struct->string++;
	}
	set_paths(mini);
}

int main(void)
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
	ft_export(mini);
}
