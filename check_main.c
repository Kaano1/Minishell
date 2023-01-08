#include "minishell.h"

int pipe_space_check(int len, char *str)
{
	while (*str == SPACE)
		str++;
	while (str[len] == SPACE)
		len--;
	str = 0;
	return (len);
}

int 	ft_pipecheck(char *str)
{
	int len;
	int	i;
	char c;

	i = 0;
	mini.pipe_count = 0;
	len = pipe_space_check(ft_strlen(str) - 1, str);
	if (str[0] == '|' || str[len] == '|')
		return (ft_error("PIPE WRONG!!!"));
	while (str[i])
	{
		if (str[i] != SPACE && str[i] != TAB)
			c = str[i];
		i++;
		if (c == '|' && str[i] == '|') 
		{
			while (len-- > i - 1)
				str[len] = 0;
		}
	}
	return (1);
}

int	ft_contqoute(char *str)
{
	int		i;
	int		once;
	int		twice;

	once = 0;
	twice = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == SIGNEL_Q && twice == 0)
			once++;
		else if (str[i] == DOUBLE_Q && once == 0)
			twice++;
		i++;
		if (once == 2 || twice == 2)
		{
			once = 0;
			twice = 0;
		}
	}
	if (once % 2 != 0 || twice % 2 != 0)
		return (ft_error("Missing character!"));
	return (1);
}
