#include "../minishell.h"

int builtin_check(char *command)
{
	if (ft_strcmp(command, "cd"))
		return (CD);
	if (ft_strcmp(command, "env"))
		return (ENV);
	if (ft_strcmp(command, "pwd"))
		return (PWD);
	if (ft_strcmp(command, "echo"))
		return (ECHO);
	if (ft_strcmp(command, "exit"))
		return (EXIT);
	if (ft_strcmp(command, "unset"))
		return (UNSET);
	if (ft_strcmp(command, "export"))
		return (EXPORT);
	return (0);
}

void    builtin_running(char **command)
{
	int where;

	where = builtin_check(command[0]);
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
