#include "../minishell.h"

void	put_str(char *str, int i)
{
	while (str[i])
	{
		write(1, &(str[i]), 1);
		i++;
	}
}

int	ft_echo_flag_check(void)
{
	int		i;
	int		is_nflag;
	int		j;

	i = 0;
	j = 1;
	is_nflag = 0;
	while (mini.iter->command[j])
	{
		if (mini.iter->command[j][i] == '-' && \
		mini.iter->command[j][i + 1] == 'n')
			is_nflag = 1;
		else
		{
			put_str(mini.iter->command[j], 0);
			write(1, " ", 1);
		}
		j++;
	}
	if (!is_nflag)
		return (0);
	return (1);
}

int	ft_echo(void)
{
	int		j;
	int		i;

	j = 0;
	i = ft_echo_flag_check();
	if (!mini.iter->string[j])
	{
		write(1, "\n", 1);
		return (0);
	}
	put_str(mini.iter->string, j);
	if (!i)
		write(1, "\n", 1);
	if (!is_parent())
		exit(EXIT_SUCCESS);
	return (0);
}
