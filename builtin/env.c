#include "../minishell.h"


int	ft_env(void)
{
    int i;

    i = 0;
    while(mini.env[i])
    {
        put_str_fd(1, mini.env[i]);
        put_str_fd(1, "\n");
        i++;
    }
    /*if (!is_parent())
		exit (EXIT_SUCCESS);*/
    return (0);
}