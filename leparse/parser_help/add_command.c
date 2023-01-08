#include "../../minishell.h"

int	check_string(char *str, int i) //we can fix this code and we could do it // 0 = command or flags or string but 1 = just string
{
	int	key;

	key = 0;
	while (str[i] == DOUBLE_Q || str[i] == SIGNEL_Q)
	{
		key = 1;
		i++;
	}
	while ((str[i] != SPACE && str[i] != 0 && str[i] != DOUBLE_Q) \
		&& (str[i] != SIGNEL_Q && str[i] != TAB))
		i++;
	if ((key == 1 && str[i] != SIGNEL_Q) \
	&& 	(str[i] != DOUBLE_Q && str[i] != 0))
		return (0);
	return (1);
}

int	ft_word_count_quotes(char *str, int *i, int len)
{
	int	type;
	int	key;
	int	index;

	key = 0;
	index = *i;
	type = str[index];
	index++;
	if (str[index] == type)
	{
		*i = index + 1;
		return (len);
	}
	while (str[index])
	{
		if (str[index] == type)
			key = 1;
		if ((str[index] == SPACE || str[index] == TAB || str[index] == 0) && key == 1)
		{
			*i = index;
			return (len + 1);
		}
		index++;
	}
	*i = index;
	return (len);
}

int	ft_word_count(char *str)//echo ahmet "ahmet ceren                                       "1 "naber ""'"325
{
	int	i;
	int	key;
	int	len;

	len = 0;
	key = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		if ((str[i] == DOUBLE_Q || str[i] == SIGNEL_Q) && key == 0)
			len = ft_word_count_quotes(str, &i, len);
		if (key == 0 && str[i] != SPACE  && str[i] != TAB)
		{
			key = 1;
			len++;
		}
		else if ((key == 1 && str[i] == SPACE) || (key == 1 && str[i] == TAB))
			key = 0;
		i++;
	}
	return (len);
}

void	where_is_command(int index, int *catch) //echo ahmet mehmet"naber"bebek > file.c 
{
    int i;
	int	j;
	int	start;
	int	word;

	i = 1;
	start = where_is_start(i, mini.parse[index]);
	if (start == -1 || !check_string(mini.parse[index], start))
	{
		mini.iter->command = ft_calloc(sizeof(char *), 1);
		mini.iter->command[0] = ft_strdup("");
		return ;
	}
	start = 0;
	mini.iter->command = ft_calloc(sizeof(char *), len_word(mini.parse[index], ' ') + 2); //look at len_word and ft_worcount fonctions
	word = ft_word_count(mini.parse[index]);
	mini.iter->command[0] = ft_add(start, index, mini.parse, 1);
	i++;
	while (word >= i)
	{
		start = where_is_start(i, mini.parse[index]);
		mini.iter->command[i - 1] = ft_add(start, index, mini.parse, 1);
		i++;
	}
	*catch = i;
}
