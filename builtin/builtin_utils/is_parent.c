#include "../../minishell.h"

int	is_parent(void)
{
	return (mini.parent_pid == getpid());
}
