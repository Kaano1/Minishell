#include "../minishell.h"

int	where_is_start(int key, int index, t_shell *mini)
{
	static int	i;
	static int	save;
	int	j;

	j = 0;
	i = save;
	if (key == 1)
		i = 0;
	if (ft_strlen(mini->parse[index]) <= i)
		return (-42);
	while (mini->parse[index][i] == ' ')
	{
		i++;
		j++;
	}
	save = i;
	while (mini->parse[index][save] != ' ' && mini->parse[index][save])
		save++;
	if (key == 3 && j > 1 && mini->parse[index][i] != '-')
		return (-42);
	if (mini->parse[index][i] == 0)
		return (-42);
	return (i);
}

char	*ft_add(int row, int column, t_shell *mini)
{
	int	i;
	char *str;

	i = row;
	str = 0;
	if (row == -1)
		return (NULL);
	while (mini->parse[column][i] != ' ')
		i++;
	str = malloc(sizeof(char) *  (i - row) + 1);
	if (!str)
		exit (-1);
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

int	getcheck_flag(char *str, int i)
{
	int	key;

	key = 0;
	while (str[i] != 0 && str[i] != '|')
	{
		if (str[i] == 34 && key == 0)
			key = 1;
		else if (str[i] == 39 && key == 0)
			key = 2;
		if (str[i] == '-')
			if ((str[i + 1] >= 97 && str[i + 1] <= 122) || (str[i + 1] >= 65 && str[i + 1] <= 90))
				break;
		i++;
		if (str[i] == 34 && key == 1)
			key = 0;
		else if (str[i] == 39 && key == 2)
			key = 0;
	}
	if (str[i] == '-')
	{
		//if (key == 1)
			//close_double();
		//else if (key == 2)
			//close_single();
		return (i);
	}
	return (-1);
}

char	*ft_flags_add(t_shell *mini, int index)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (len != index && mini->check_parser[++i])
		if (mini->check_parser[i][0] == '|')
			len++;
	i += 2;
	if (mini->check_parser[i] == 0)
		i++;
	
	exit (0);
	return (0);
}

void	ft_add_struct(t_shell *mini)
{
	int	i;

	i = 0;
	while (i < mini->pipe_count + 1)
	{
		mini->first_struct->command = ft_add(where_is_command(i, mini), i, mini);
		mini->first_struct->flag = ft_flags_add(mini, i);
		printf("COMMAND: %s\n", mini->first_struct->command);
		printf("FLAGS: %s\n", mini->first_struct->flag);
		exit (0);
		//mini->first_struct->string = ft_add(where_is_start(0, i, mini), i, mini);
		if (mini->first_struct->redirect != 0)
		{
			mini->first_struct->file_name = ft_add(where_is_start(0, i, mini), i, mini);
		}
		i++;
	}
    exit (0);
}
//where is command, where is flags, where is string and where is file_name yapalım
//ortak noktaları olursa onları bir fonksiyonda kullanalım
// ahmet
// -d
// mehmet
// |
// ceren
// -c
//