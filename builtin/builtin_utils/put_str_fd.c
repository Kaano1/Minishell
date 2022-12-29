#include "../../minishell.h"

void	put_str_fd(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}
