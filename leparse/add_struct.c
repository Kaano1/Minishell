#include "../minishell.h"

int	where_is_start(int count_word, char *str)
{
	int	i;
	int	key;
	int	len;

	i = 0;
	len = 0;
	key = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (len == count_word)
			break;
		if (str[i] == DOUBLE_Q || str[i] == SIGNEL_Q)
		{
			if (i != 0 && str[i - 1] == SPACE)
				len++;
			if (len == count_word)
				break;
			i = where_is_end(i, str, str[i]);
		}
		else if (key == 0 && str[i] != SPACE && str[i] != TAB)
		{
			len++;
			key = 1;
		}
		else if (key == 1 && (str[i] == SPACE || str[i] == TAB))
			key = 0;
		else
			i++;
	}
	return (i);
}

int	where_is_end(int start, char *parse, int type)
{
	int	key;

	key = 1;
	while (parse[start])
	{
		start++;
		if (parse[start] == type && parse[start + 1] != type)
			key = 0;
		else if ((parse[start] == SPACE || parse[start] == TAB) && key == 0)
			break;
		else if ((parse[start] == DOUBLE_Q || parse[start] == SIGNEL_Q) && key == 0)
		{
			type = parse[start];
			key = 1;
		}
	}
	if (parse[start] == SPACE || parse[start] == TAB)
		start--;
	return (start + 1);
}

char	*ft_add_quotes(int column, int start, char **parse, int type)
{
	char	*str;
	int		i;
	int		end;

	while (parse[column][start] == type)
		start++;
	end = where_is_end(start, parse[column], type);
	if (start >= end)
		return (NULL);
	str = ft_calloc(sizeof(char) ,(1 + end - start));
	i = 0;
	while (start < end)
	{
		while (parse[column][start] == DOUBLE_Q || parse[column][start] == SIGNEL_Q)
			start++;
		if (start < end)
			str[i] = parse[column][start];
		start++;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_add(int start, int column, char **parse, int key)
{
	int		i;
	char	*str;

	if (start == -1)
		return (NULL);
	if (parse[column][start] == DOUBLE_Q || parse[column][start] == SIGNEL_Q)
		return (ft_add_quotes(column, start, mini.parse, parse[column][start]));
	i = where_is_end(start, parse[column], ' ');
	str = ft_calloc(sizeof(char), i - start + 1);
	if (!str)
		exit (-1);
	i = 0;
	if (column > 0 && key == 1 && start <= 1)
		start = 1;
	while (parse[column][start] && parse[column][start] != SPACE && parse[column][start] != TAB)
	{
		while (parse[column][start] == DOUBLE_Q || parse[column][start] == SIGNEL_Q)
			start++;
		str[i] = parse[column][start];
		start++;
		i++;
	}
	str[i] = 0;
	return (str);
}

void	ft_add_struct(void) // echo kaan""nbrfucksssssssssssssssecho kaan""nbrfucksssssssssssssssecho kaan""nbrfucksssssssssssssssecho kaan""nbrfucksssssssssssssss
{
	int		start;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mini.iter = mini.first_struct;
	start = 0;
	while (mini.iter && i < mini.pipe_count + 1)
	{
		where_is_command(i, &start);
		i++;
		mini.iter = mini.iter->next;
	}
	i = 0;
	mini.iter = mini.first_struct;
}
