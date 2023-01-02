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
void    builtin_running(char **tmp)
{
    int where;

    where = builtin_check(tmp[0]);
    if (where == 0)
        return ;
	if (where == ECHO)
		ft_echo(tmp);
	else if (where == CD)
		ft_cd(tmp);
    else if (where == ENV)
        ft_env();
    else if (where == EXIT)
        ft_exit(tmp);
    else if (where == PWD)
        ft_pwd();
    else if (where == EXPORT)
        ft_export(tmp);
    else if (where == UNSET)
        ft_unset(tmp);
}
