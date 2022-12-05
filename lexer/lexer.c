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
	tmp = 0;
	/*
	if (ft_strcmp(tmp, "echo"))
		echo();
	else if(ft_strcmp(tmp, "cd"))
		cd();
	else if(ft_strcmp(tmp, "pwd"))
		pwd();
	else if(ft_strcmp(tmp, "export"))
		export();
	else if(ft_strcmp(tmp, "unset"))
		unset();
	else if(ft_strcmp(tmp, "env"))
		env();
	else if(ft_strcmp(tmp, "exit"))
		funcition_exit();
	else
		function_exec(tmp);
	*/
}

void    ft_lexer(t_shell *mini)
{
    int i;
    int j;
    int k;
    int c;
    char *tmp;

    i = 0;
    while (mini->parse[i])
    {
		j = 0;
        while (mini->parse[i][j] == ' ')
            j++;
        c = j;
        while (mini->parse[i][c] != ' ')
            c++;
		tmp = malloc(sizeof(char) * c - j + 1);
		k = 0;
        while (mini->parse[i][j] != ' ')
        {
            tmp[k] = mini->parse[i][j];
            k++;
            j++;
        }
		tmp[k] = 0;
		control(tmp);
		i++;
    }
}
