#include "../minishell.h"

void	set_paths()
{
	char	*npath;

	if (mini.path)
		free_array(mini.path);
	npath = get_env(ft_strdup("PATH"));
	if (!(*npath))
		mini.path = NULL;
	else
		mini.path = ft_mysplit(npath, ':');
	free(npath);
}
