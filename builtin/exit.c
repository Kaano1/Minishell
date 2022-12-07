#include "../minishell.h"
// sayı olmasa da normal terminal çıkış yapıyor
int	ft_exit(t_shell *mini)
{
	int	num;
    
    num = 0;
	if (mini->first_struct->string)
		num = ft_atoi(mini->first_struct->string);
	exit(num);
}

