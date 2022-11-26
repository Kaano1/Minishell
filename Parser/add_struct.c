#include "../minishell.h"

int	where_is_start(int key, int index, t_shell *mini)
{
	static int	i;
	static int	save;
	int	j;

	j = 0;
	if (key == 1)
		i = 0;
	else
		i = save;
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
	if (row == -42)
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

void	ft_add_struct(t_shell *mini)
{
	int	i;

	i = 0;
	while (i < mini->pipe_count + 1)
	{
        printf("HELLO");
        printf("%s\n", mini->parse[i]);
		mini->first_struct->command = ft_add(where_is_start(1, i, mini), i, mini);
		mini->first_struct->flag = ft_add(where_is_start(3, i, mini), i, mini);
		mini->first_struct->string = ft_add(where_is_start(0, i, mini), i, mini);
		if (mini->first_struct->redirect != 0)
			mini->first_struct->file_name = ft_add(where_is_start(0, i, mini), i, mini);
		i++;
	}
    exit (0);
}
