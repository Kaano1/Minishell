#include "../minishell.h"

void	put_str(char *str, int i)
{
	while (str[i])
	{
		write(1, &(str[i]), 1);
		i++;
	}
}
// -n flag varsa index yoksa 0 döndürür
// command[1][i] 
// ----- kontrolü yap

int	ft_echo_flag_check(void)
{
	int i;
	int is_nflag;

	i = 0;
	is_nflag = 0;
	while(mini.iter->string[i] == '-' || mini.iter->string[i] == ' ')
	{
		if((mini.iter->string[i] == '-') && (mini.iter->string[i + 1] == 'n'))
		{
			i++;
			while(mini.iter->string[i] == 'n' && mini.iter->string[i + 1] == 'n')
				i++;
			is_nflag = 1;
		}
		i++;
	}
	if(!is_nflag)
		return(0);
	return(1);
}

int	ft_echo(void)
{
	int	i;

    i = ft_echo_flag_check();
	if (!mini.iter->string[i])
	{
		write(1, "\n", 1);
		return (0);
    }
	put_str(mini.iter->string, i);
    i = ft_echo_flag_check();
    if(!i)
        write(1, "\n", 1);
	/*if (!is_parent())
		exit(EXIT_SUCCESS);*/
    return(0);

}
