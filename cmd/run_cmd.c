/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:15:09 by fkaratay          #+#    #+#             */
/*   Updated: 2023/01/04 19:50:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pipe_route(t_command *process)
{
	if (process->prev == NULL)
		dup2(process->fd[1], 1);
	else if (process->next == NULL)
		dup2(process->prev->fd[0], 0);
	else
	{
		dup2(process->prev->fd[0], 0);
		dup2(process->fd[1], 1);
	}
}

void	heredoc_route(t_command *process)
{
	dup2(process->heredoc_fd[0], 0);
	if (process->next != NULL)
		dup2(process->fd[1], 1);
}

void	cmd_route(t_command *process)
{
	if (mini.pipe_count > 0)
	{
		if (contain_heredoc(process))
			heredoc_route(process);
		else
			pipe_route(process);
	}
	get_all_inputs(process);
	set_all_outputs(process);
	close_all_fd();
}

void	run_cmd(t_command *process)
{
	pid_t	pid;
	char	*path;

	pid = fork();
	if (pid == CHILD_PROCESS)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		cmd_route(process);
		builtin_running(process->command);
		path = get_path(process->command[0]);
		execve(path, process->command, mini.env);
		command_err(process->command[0]);
		exit(errno);
	}
	else
		process->pid = pid;
}
