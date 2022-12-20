#include "../minishell.h"

void	ft_pwd(void)
{
	char	*way;

	way = getcwd((void *)0, 0);
	if (!way)
		perror("minishell ");
	else
		put_strnl_fd(1, way);
	free(way);
	if (!is_parent())
		exit(errno);
}
