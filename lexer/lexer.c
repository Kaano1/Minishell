#include "../minishell.h"

char	*ft_exec_join(char *tmp, char *bin)
{
	char *str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(tmp) + 6));
	while (tmp[i])
	{
		str[i] = bin[i];
		i++;
	}
	return (0);
}

void function_exec(char *tmp)
{
	char *exec;

	exec = ft_exec_join(tmp, "/bin/"); //execute mü?
	/*if (execve(exec, NULL, NULL))
	{
		printf("girdi");
	}*/
	free(exec);
}

void	control(char *tmp)
{
	if (!ft_strncmp(tmp, "echo", 4))
		ft_echo();
	else if (!ft_strncmp(tmp, "cd", 2))
		ft_cd();
	else if (!ft_strncmp(tmp, "env", 3))
		ft_env();
	else if (!ft_strncmp(tmp, "exit", 4))
		ft_exit();
	else if (!ft_strncmp(tmp, "pwd", 3))
		ft_pwd();
	else if (!ft_strncmp(tmp, "export", 6))
		ft_export();
	else if (!ft_strncmp(tmp, "unset", 5))
		ft_unset();
	else
	{
		put_str("bash: ", 0);
		put_str(mini.iter->command[0], 0);
		put_str(" command not found\n", 0);
	}
	//else
		//function_exec(tmp);
}

void    ft_lexer(void)
{
	control(mini.iter->command[0]);
}
