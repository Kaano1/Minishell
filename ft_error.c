#include "minishell.h"

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit (0);
}

int ft_space_check(int len, t_shell *mini)
{
	int	i;

	i = 0;
	while (*mini->all_line == ' ')
	{
		mini->all_line++;
	}
	while (mini->all_line[len] == ' ')
	{
		len--;
	}
	mini->all_line[len + 1] = 0;
	return (len);
}

void 	ft_pipecheck(t_shell *mini)
{
	int len;
	int	i;
	char c;

	len = 0;
	i = 0;
	mini->pipe_count = 0;
	while (mini->all_line[len])
		len++;
	len--;
	len = ft_space_check(len, mini);
	if (mini->all_line[0] == '|' || mini->all_line[len] == '|')
		ft_error("WRONG!!!");
	while (mini->all_line[i])
	{
		if (mini->all_line[i] != ' ')
			c = mini->all_line[i];
		i++;
		if (c == '|' && mini->all_line[i] == '|')
		{
			while (len-- > i - 1)
				mini->all_line[len] = 0;
		}
	}
}

void	ft_pipe_count(t_shell *mini)
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