#include "../minishell.h"

int	just_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32 && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
