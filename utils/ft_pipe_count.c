#include "../minishell.h"

void	ft_pipe_count(char *str) //pipe sayimizi tutuyor ileride pipe counta gore struct ve fork yapicaz.
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			mini.pipe_count++;
		i++;
	}
}