#include "minishell.h"

int	ft_error(char *str)
{
	printf("%s\n", str);
	return (0);
}

void	no_file_err(char *str)
{
	if (ft_strchr(str, '/'))
		errno = 127;
	else
		errno = 1;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": No such file or directory\n", 28);
	if (!is_parent())
		exit(errno);
}

void	directory_err(char *str)
{
	errno = 126;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": is a directory\n", 17);
	if (!is_parent())
		exit(errno);
}

void	command_err(char *str)
{
	errno = 127;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": command not found\n", 20);
	if (!is_parent())
		exit(errno);
}