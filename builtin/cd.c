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


int	ft_cd(void)
{
	int		err;
	char	*home;

	if (!mini.iter->string)
	{
		home = getenv("HOME");
        chdir(home);
    }
	else
	{
		err = chdir(mini.iter->string);
		if (err)
		{
			put_error(mini.iter->string);
			return (1);
		}
	}
	/*if (!is_parent())
		exit(errno);*/
	return (0);
}
