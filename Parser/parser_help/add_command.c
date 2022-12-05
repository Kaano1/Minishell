#include "../../minishell.h"

int	check_string(char *str, int i) //we can fix this code and we could do it // 0 = command or flags or string but 1 = just string
{
	int	key;

	key = 0;
	while (str[i] == 34 || str[i] == 39)
	{
		key = 1;
		i++;
	}
	while (str[i] != 32 && str[i] != 0 && str[i] != 34 && str[i] != 39)
		i++;
	if ((key == 1 && str[i] != 39) || (key == 1 && str[i] != 34))
		return (0);
	return (1);
}

char	**where_is_command(int index, t_shell *mini, int *catch)
{
    int i;
	int	j;
	int	start;

	i = 1;
	start = where_is_start(i, mini->parse[index]);
	if (!check_string(mini->parse[index], start))
		return (0);
	mini->first_struct->command = ft_calloc(sizeof(char *), len_word(mini->parse[index], ' ') + 1);
	mini->first_struct->command[0] = ft_add(start, index, mini);
	i++;
	while (1)
	{
		start = where_is_start(i, mini->parse[index]);
		j = start;
		while (mini->parse[index][j] == 34 || mini->parse[index][j] == 39)
			j++;
		if (mini->parse[index][j] == '-' && check_string(mini->parse[index], start))
			mini->first_struct->command[i - 1] = ft_add(j, index, mini);
		else
			break;
		i++;
	}
	*catch = i;
    return (mini->first_struct->command);
}
