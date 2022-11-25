#include "../minishell.h"

void	ft_create_struct(t_shell *mini)
{
	t_command	*first;
	int i;

	mini->first_struct = malloc(sizeof(t_command));
	first = mini->first_struct;
	i = 0;
	while (i < mini->pipe_count)
	{
		mini->first_struct->next = malloc(sizeof(t_command));
		mini->first_struct = mini->first_struct->next;
		i++;
	}
	mini->first_struct = first;
}

int	where_is_start(int key, int index, t_shell *mini)
{
	static int	i;
	int	j;

	j = 0;
	if (key == 1)
		i = 0;
	while (mini->parse[index][i] == ' ')
	{
		i++;
		j++;
	}
	if (key == 3 && j > 1)
		return (-42);
	if (i == ft_strlen(mini->parse[index]))
		return (-1);
	return (i);
}

char	*ft_add(int row, int column, t_shell *mini)
{
	int	i;
	char *str;

	i = row;
	str = 0;
	if (row == -42)
		return (NULL);
	while (mini->parse[column][i] != ' ')
		i++;
	while (!str)
		str = malloc(sizeof(char) *  (i - row) + 1);
	i = 0;
	while (mini->parse[column][row] != ' ')
	{
		str[i] = mini->parse[column][row];
		row++;
		i++;
	}
	str[i] = 0;
	return (str);
}

void	ft_add_struct(t_shell *mini)
{
	int	i;

	i = 0;
	while (i < mini->pipe_count + 1)
	{
		mini->first_struct->command = ft_add(where_is_start(1, i, mini), i, mini);
		mini->first_struct->flag = ft_add(where_is_start(3, i, mini), i, mini);
		mini->first_struct->string = ft_add(where_is_start(0, i, mini), i, mini);
		if (mini->first_struct->redirect != 0)
			mini->first_struct->file_name = ft_add(where_is_start(0, i, mini), i, mini);
		i++;
	}
}

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
    str[save_i + 1] = 0;
    return (str);
}

void	ft_parse(t_shell *mini)
{
	int		i;

	i = 0;
	mini->parse = ft_mysplit(mini->all_line, ' ');
	mini->parse = find_dollar_and_change(mini);
	mini->all_line = ft_join_arg(mini);
	mini->parse = ft_mysplit(mini->all_line, '|');
	printf("%s", mini->parse[0]);
	exit (0);
	ft_create_struct(mini);
	mini->iter = mini->first_struct;
	while (mini->iter)
	{
		mini->iter->redirect = ft_redirect(mini);
		mini->iter = mini->iter->next;
	}
	mini->iter = mini->first_struct;
	ft_add_struct(mini);
	while (mini->parse[i])
	{
		printf("%s\n", mini->parse[i]);
		i++;
	}
}