#include "../minishell.h"

int	ft_redirect(t_shell *mini)
{
	int	i;
	static int j = 0;

	i = 0;
	while (mini->parse[j][i])
	{
		if (mini->parse[j][i] == '>')
		{
			if (mini->parse[j][i + 1] == '>')
				return (4);
			return (2);
		}
		else if (mini->parse[j][i] == '<')
		{
			if (mini->parse[j][i + 1] == '<')
				return (3);
			return (1);
		}
		i++;
	}
	j++;
	return (0);
}

void	ft_create_struct(t_shell *mini)
{
	t_command	*first;
	int i;

	mini->first_struct = malloc(sizeof(t_command));
	first = mini->first_struct;
	i = 0;
	while (i < mini->pipe_count + 1)
	{
		mini->first_struct->next = malloc(sizeof(t_command));
		mini->first_struct->command = 0;
		mini->first_struct->flag = 0;
		mini->first_struct->string = 0;
		mini->first_struct->redirect = ft_redirect(mini);
		mini->first_struct->file_name = 0;
		mini->first_struct = mini->first_struct->next;
		i++;
	}
	mini->first_struct = first;
}

size_t	len_word2(char **s)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = 0;
	while (s[++i])
		len += ft_strlen(s[i]);
	len += i;
	return (len);
}

char	*ft_join_arg(t_shell *mini)
{
	char	*str;
	int		i;
	int		j;
	int		save_i;

	str = malloc(sizeof(char) * len_word2(mini->parse));
	j = 0;
	save_i = 0;
	while (mini->parse[j])
	{
		i = 0;
		if (mini->parse[j][i] == 0 && mini->parse[j + 1][i] != 0)
			j++;
		while (mini->parse[j][i])
		{
			str[save_i] = mini->parse[j][i];
			i++;
			save_i++;
		}
		if (mini->parse[j] != 0)
        	str[save_i++] = 32;
		j++;
	}
    str[save_i] = 0;
    return (str);
}

void	ft_parse(t_shell *mini)
{
	int		i;

	i = -1;
	mini->parse = ft_mysplit(mini->all_line, ' ', 1);
	mini->check_parser = ft_mysplit(mini->all_line, ' ', 1);
	mini->parse = find_dollar_and_change(mini);
	mini->all_line = ft_join_arg(mini);
	mini->parse = ft_mysplit(mini->all_line, ' ', 0);
	printf("%s", mini->parse[0]);
	ft_create_struct(mini);
	mini->iter = mini->first_struct;
	ft_add_struct(mini);
	exit (0);
	printf("command: %s\n", mini->first_struct->command);
	printf("flags: %s\n", mini->first_struct->flag[0]);
	printf("string: %s\n", mini->first_struct->string);
	printf("file_name: %s\n", mini->first_struct->file_name);
	exit (0);
	while (mini->parse[i])
	{
		printf("%s\n", mini->parse[i]);
		i++;
	}
}