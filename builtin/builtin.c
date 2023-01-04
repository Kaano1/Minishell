#include "../minishell.h"

int builtin_check(char *tmp)
{
	if (!ft_strncmp(tmp, "echo", 4))
		return (ECHO);
	else if (!ft_strncmp(tmp, "cd", 2))
		return (CD);
	else if (!ft_strncmp(tmp, "env", 3))
		return (ENV);
	else if (!ft_strncmp(tmp, "exit", 4))
		return (EXIT);
	else if (!ft_strncmp(tmp, "pwd", 3))
		return (PWD);
	else if (!ft_strncmp(tmp, "export", 6))
		return (EXPORT);
	else if (!ft_strncmp(tmp, "unset", 5))
		return (UNSET);
	return (0);
}

void    builtin_running(char **command)
{
	int where;

	where = builtin_check(command[0]);
	if (where == 0)
		return ;
	if (where == ECHO)
		ft_echo(command);
	else if (where == CD)
		ft_cd(command);
	else if (where == ENV)
		ft_env();
	else if (where == EXIT)
		ft_exit(command);
	else if (where == PWD)
		ft_pwd();
	else if (where == EXPORT)
		ft_export(command);
	else if (where == UNSET)
		ft_unset(command);
}
