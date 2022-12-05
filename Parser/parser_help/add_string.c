#include "../../minishell.h"

int	flagslen(t_shell *mini, int index)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++j < index)
		mini->first_struct = mini->first_struct->next;
	// (mini->first_struct->flag[i] != 0)
		i++;
	mini->first_struct = mini->iter;
	return (i);
}

char	*ft_add_string(t_shell *mini, int index)
{
	char	*str;
	int		len;
	int		i;

	i = 1;
	while (mini->parse[index][i] != 32 && mini->parse[index][i] != '\t' && mini->parse[index][i] != 0)
		i++;
    if (ft_strlen(mini->parse[index]) == i)
        return (0);
    len = flagslen(mini, index);
	//if (mini->first_struct->flag[0] != 0)
		while (len != 0)
		{
			if (mini->parse[index][i] == '-')
			{
				while (mini->parse[index][i] != 0 && mini->parse[index][i] != 32 && mini->parse[index][i] != '\t')
					i++;
				len--;
			}
			i++;
		}
//	else
        i++;
	str = malloc(sizeof(char) * (ft_strlen(mini->parse[index]) - i));
	len = 0;
	while (mini->parse[index][i] != 0 && mini->parse[index][i] != '<' && mini->parse[index][i] != '>') //redirection add +++
	{
		str[len] = mini->parse[index][i];
		len++;
		i++;
	}
	str[len] = 0;
    return (str);
}