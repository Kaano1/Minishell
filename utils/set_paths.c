#include "../minishell.h"

void	set_paths()
{
	char	*npath;

	if (mini.path)
		printf("girdi");
		//free_array(mini.path);
	npath = get_env("PATH");
	if (!(*npath))
		mini.path = NULL;
	else
		mini.path = ft_mysplit(npath, ':');
	free(npath);
}
