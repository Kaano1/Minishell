#include "../minishell.h"

void	free_process(void)
{
	t_command	*tmp;
	t_command	*process;

	process = mini.first_struct;
	if (!process)
		return ;
	while (process)
	{
		free_array(process->command);
		free_array(process->redirect);
		tmp = process;
		process = process->next;
		free(tmp);
	}
}
