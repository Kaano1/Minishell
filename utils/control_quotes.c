#include "../minishell.h"

int control_quotes(char *str)
{
    int i;
    int key;

    i = 0;
    key = 0;
    while ((str[i] == 32 || str[i] == '\t' || str[i] == 34 || str[i] == 39) && str[i] != 0)
    {
        if (str[i] == 34 || str[i] == 39)
            key = 1;
        if (str[i] != 32 && str[i] != '\t' && str[i] != 34 && str[i] != 39)
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