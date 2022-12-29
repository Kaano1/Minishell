#include "../../minishell.h"

void	put_strnl_fd(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
	write(1, "\n", 1);
}
