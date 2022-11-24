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

size_t	len_word2(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			len++;
		s++;
	}
	return (len);
}

char	*ft_join_arg(t_shell *mini)
{
	char	*str;
	int		i;
	int		j;
	int		save_i;

	str = malloc(sizeof(char) * ft_strlen(mini->all_line) + len_word2(mini->all_line, ' ') + 1);
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
        str[save_i++] = 32;
		j++;
	}
    str[save_i + 1] = 0;
    return (str);
}

char	*get_after_dollar_osman(char *parse, int index)
{
	char	*str;
	int		i;

	i = index;
	while (parse[i] != ' ' && parse[i] != 0)
		i++;
	if (i == index)
		return (0);
	str = malloc(sizeof(char) * (i - index) + 1);
	i = 0;
	while (parse[index] != ' ' && parse[index] != 0)
	{
		str[i] = parse[index];
		i++;
		index++;
	}
	str[i] = 0;
	return (str);
}

char	*switch_to_parse(char *tmp, int	prs_index, t_shell *mini)
{
	char	*str;
	int		tm_i;
	int		j;
	int		i;
	int		key;

	
	tm_i = 0;
	i = 0;
	j = 0;
	key = 1;
	str = malloc(sizeof(char) * (ft_strlen(tmp)) + 1);
	while (ft_strlen(mini->parse[prs_index]) > j)
	{
		if (mini->parse[prs_index][j] == '$' && key)
		{		
			key = 0;
			while (mini->parse[prs_index][j] != ' ' && mini->parse[prs_index][j] != 0)
				j++;
			while (tmp[tm_i])
			{
				str[i] = tmp[tm_i];
				i++;
				tm_i++;
			}
		}
		else
		{
			str[i] = mini->parse[prs_index][j];
			i++;
			j++;
		}
	}
	str[i] = 0;
	free(mini->parse[prs_index]);
	return (str);
}

char	*get_env_osman(char *str, t_shell *mini)
{
	char	*string;
	int		i;
	int		j;
	int		d;
	int		longg;

	i = 0;
	string = 0;
	while (mini->env[i])
	{
		if ((ft_memcmp(mini->env[i], str, ft_strlen(str))) == 0)
		{
			if (mini->env[i][ft_strlen(str)] == '=')
			{
				d = 0;
				longg = ft_strlen(mini->env[i]) - ft_strlen(str);
				string = malloc(sizeof(char) * longg);
				j = ft_strlen(str) + 1;
				while (longg > d)
				{
					string[d] = mini->env[i][j];
					d++;
					j++;
				}
			}
		}
		i++;
	}
	if (!string)
		return (NULL);
	return (string);
}

char	*create_switch_to_zero(int i, int j, int prs_index, t_shell *mini)
{
	char	*str;
	int		z;
	int		key;

	z = 0;
	key = 0;
	str = malloc(sizeof(char) * (ft_strlen(mini->parse[prs_index]) - j) + 1);
	j = 0;
	while (mini->parse[prs_index][j])
	{
		if (key == 0 && mini->parse[prs_index][j] == '$')
		{
			j = i;
			key = 1;
		}
		str[z] = mini->parse[prs_index][j];
		z++;
		j++;
	}	
	str[z] = 0;
	return (str);
}

char	*switch_to_zero(int	prs_index, t_shell *mini)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mini->parse[prs_index][i])
	{
		if (mini->parse[prs_index][i] == '$' && mini->parse[prs_index][i + 1] !=  ' ' && mini->parse[prs_index][i] != 0)
		{
			while (mini->parse[prs_index][i] != 32 && mini->parse[prs_index][i] != 0)
			{
				i++;
				j++;
			}
			break;
		}
		i++;
	}
	return (create_switch_to_zero(i, j, prs_index, mini));
}

int	count_null(t_shell *mini, int count_parse)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count_parse)
	{
		if (mini->parse[i][0] == 0)
			j++;
		i++;
	}
	return (j);
}

char	**check_or_fix_switch(t_shell *mini, int count_parse)
{
	char	**mini_parse;
	int		null;
	int		i;
	int		j;

	null = count_null(mini, count_parse);
	if (null == 0)
		return (mini->parse);
	i = 0;
	j = 0;
	mini_parse = malloc(sizeof(char *) * count_parse - null + 1);
	while (i < count_parse)
	{
		if (mini->parse[i][0] != 0)
		{
			mini_parse[j] = ft_strdup(mini->parse[i]);
			j++;
		}
		i++;
	}
	mini_parse[j] = 0;
	i = -1;
	while (++i < count_parse)
		free(mini->parse[i]);
	free(mini->parse);
	return (mini_parse);
}

char	**find_dollar_and_change(t_shell *mini)
{
	char	*tmp;
	int	i;
	int	j;

	i = 0;
	while (mini->parse[i])
	{
		j = 0;
		while (mini->parse[i][j])
		{
			if (mini->parse[i][j] == '$' && mini->parse[i][j + 1] != ' ' && mini->parse[i][j + 1] != 0)
			{
				tmp = get_env_osman(get_after_dollar_osman(mini->parse[i], j + 1), mini);
				if (!tmp)
					mini->parse[i] = switch_to_zero(i, mini);
				else
					mini->parse[i] = switch_to_parse(tmp, i, mini);
			}
			j++;
		}
		i++;
	}
	return (check_or_fix_switch(mini, i));
}

void	ft_parse(t_shell *mini)
{
	int		i;

	i = 0;
	mini->parse = ft_mysplit(mini->all_line, ' ');
	mini->parse = find_dollar_and_change(mini);
	mini->all_line = ft_join_arg(mini);
	printf("%s", mini->all_line);
	exit (0);
	mini->parse = ft_mysplit(mini->all_line, '|');
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