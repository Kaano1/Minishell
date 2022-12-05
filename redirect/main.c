#include "../minishell.h"

int redirect(char **str)
{
    int i = 0;
    char *file_name;

    while(str[i])
    {
        if(*str[i] == '>')
        {
            file_name = str[i + 1];
            input(file_name, '>');
        }
        else if(*str[i] == '>>')
        {
            file_name = str[i + 1];
            input(file_name, '>>');
        }
        else if(*str)
        i += 2;
    }
}

int main(int ac, char **av)
{
    char **str;
    str = (char **)malloc(sizeof(char *));
    char *str[0] = '>';
    char *str[1] = 'Ahmet';
    char *str[2] = '>>';
    char *str[3] = 'Mehmet';
    
    redirect(str);

}