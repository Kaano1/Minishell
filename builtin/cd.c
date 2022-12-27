#include "../minishell.h"

static void	put_error(char *str)
{
	char	*msg;

	msg = strerror(2);
	put_str_fd(2, "cd: ");
	put_str_fd(2, msg);
	put_str_fd(2, ": ");
	put_str_fd(2, str);
}

int	ft_cd(char **execute)
{
	int		err;
	char	*home;

	if (!execute[1])
	{
		home = getenv("HOME");
		chdir(home);
	}
	else
	{
		if (execute[2] != 0)
		{
			printf("cd: too many arguments\n");
			return (1);
		}
		err = chdir(execute[1]);
		if (err)
		{
			put_error(execute[1]);
			return (1);
		}
	}
	if (!is_parent())
		exit(errno);
	return (0);
}
