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
void	put_str_fd(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

