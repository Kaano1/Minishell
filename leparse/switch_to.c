#include "../minishell.h"

char	*switch_to_zero(int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mini.parse[k][i])
	{
		if (mini.parse[k][i] == '$' && mini.parse[k][i + 1] != ' ' \
			&& mini.parse[k][i] != 0)
		{
			while ((mini.parse[k][i] != SPACE && mini.parse[k][i] != 0) \
				|| (mini.parse[k][i] != TAB && mini.parse[k][i] != 0))
			{
				i++;
				j++;
			}
			break ;
		}
		i++;
	}
	return (create_switch_to_zero(i, j, k));
}

char	*create_switch_to_zero(int i, int j, int prs_index)
{
	char	*str;
	int		z;
	int		key;

	z = 0;
	key = 0;
	str = malloc(sizeof(char) * (ft_strlen(mini.parse[prs_index]) - j) + 1);
	j = 0;
	while (mini.parse[prs_index][j])
	{
		if (key == 0 && mini.parse[prs_index][j] == '$')
		{
			j = i;
			key = 1;
		}
		str[z] = mini.parse[prs_index][j];
		z++;
		j++;
	}	
	str[z] = 0;
	return (str);
}

char	*switch_shorter(char *str, int *index, int *jindex, char *tmp)
{
	int	tm_i;
	int	k;
	int	i;
	int	j;

	i = *index;
	j = *jindex;
	tm_i = 0;
	k = mini.temporary;
	while (mini.parse[k][j] != ' ' && mini.parse[k][j] != 0 && \
	mini.parse[k][j] != DOUBLE_Q && mini.parse[k][j] != SIGNEL_Q)
		j++;
	while (tmp[tm_i])
	{
		str[i] = tmp[tm_i];
		i++;
		tm_i++;
	}
	*index = i;
	*jindex = j;
	return (str);
}

char	*switch_to_parse(char *tmp, int k)
{
	int		j;
	int		i;
	int		key;
	char	*str;

	i = 0;
	j = 0;
	key = 1;
	str = ft_calloc(sizeof(char), ft_strlen(tmp) + ft_strlen(mini.parse[k]));
	mini.temporary = k;
	while (ft_strlen(mini.parse[k]) > j)
	{
		if (mini.parse[k][j] == '$' && key)
		{
			key = 0;
			str = switch_shorter(str, &i, &j, tmp);
		}
		else
			str[i++] = mini.parse[k][j++];
	}
	str[i] = 0;
	return (str);
}
