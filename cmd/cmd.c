#include "../minishell.h"

void	start_cmd(void)
{
	t_command	*process;

	process = mini.first_struct;
	if (!process)
		return ;
	fill_all_heredoc();
	if (mini.ignore)
		return (close_all_fd());
	if (is_builtin(process->command[0]) && mini.pipe_count == 1)
	{
		get_builtin(process);
		process = process->next;
	}
	while (process)
	{
		run_cmd(process);
		process = process->next;
	}
	wait_cmd();
}
