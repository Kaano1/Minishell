#include "../minishell.h"

int control_quotes(char *str)
{
    int i;
    int key;

    i = 0;
    key = 0;
    while ((str[i] == SPACE || str[i] == TAB || \
        str[i] == DOUBLE_Q || str[i] == SIGNEL_Q) && str[i] != 0)
    {
        if (str[i] == DOUBLE_Q || str[i] == SIGNEL_Q)
            key = 1;
        if (str[i] != SPACE && str[i] != TAB && \
             str[i] != DOUBLE_Q && str[i] != SIGNEL_Q)
            return (1);
        i++;
    }
    if (key == 1 && str[i] == 0)
    {
		printf("Command '' not found!\n");
        return (0);
    }
    return (1);
}