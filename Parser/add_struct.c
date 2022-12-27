#include "../minishell.h"

int	where_is_start(int count_word, char *str)
{
	int	i;
	int	key;
	int	len;

	i = 0;
	key = 0;
	len = 0;
	if (!str)
		return (-1);
	while (str[i] != 0)
	{
		if ((str[i] != 32 && key == 0) || (str[i] != '\t' && key == 0))
		{
			key = 1;
			len++;
		}
		else if ((key == 1 && str[i] == 32) || (key == 1 && str[i] == '\t'))
			key = 0;
		if (len == count_word)
			break ;
		i++;
	}
	return (i);
}

int	where_is_end(int column, int start, char **parse, int type)
{
	while (parse[column][start])
	{
		start++;
		if (parse[column][start - 1] == type && parse[column][start] == 32)
			break;
		else if (parse[column][start - 1] == type && parse[column][start] == '\t')
			break;
	}
	while (parse[column][start] == type)
		start--;
	return (start);
}

char	*ft_add_quotes(int column, int start, char **parse, int type)
{
	char	*str;
	int		i;
	int		end;

	while (parse[column][start] == type)
		start++;
	end = where_is_end(column, start, parse, type);
	if (start >= end)
		return (NULL);
	str = malloc(sizeof(char) * (1 + end - start));
	i = 0;
	while (start < end)
	{
		while (parse[column][start] == 34 || parse[column][start] == 39)
			start++;
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

	i = start;
	if (start == -1)
		return (NULL);
	if (parse[column][i] == 34 || parse[column][i] == 39)
		return (ft_add_quotes(column, start, mini.parse, parse[column][i]));
	str = ft_calloc(sizeof(char), i - start + 1);
	if (!str)
		exit (-1);
	i = 0;
	if (column > 0 && key == 1 && start <= 1)
		start = 1;
	while (parse[column][start] && parse[column][start] != ' ')
	{
		while (parse[column][start] == 34 || parse[column][start] == 39)
			start++;
		str[i] = parse[column][start];
		start++;
		i++;
	}
	str[i] = 0;
	return (str);
}

void	ft_add_struct(void) // fjlakdjlkafjdflakdjlkfajlkfjdlkjfdaflkadjlfkajdlkfjdlkjflkajdflkadjlfkjdalkfjalkfjdklsfajdkf | ceren
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
	mini.iter = mini.first_struct;
}
