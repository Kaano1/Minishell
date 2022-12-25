#include "../minishell.h"

int	contain_heredoc(t_command *process)
{
	int	i;

	i = 0;
	while (process->redirect[i])
	{
		if (is_operator(process->redirect[i]) == HERE_DOC)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
