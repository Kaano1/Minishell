#include "../minishell.h"
// sayı olmasa da normal terminal çıkış yapıyor
int	ft_exit(void)
{
	int	num;
    
    num = 0;
	if (mini.iter->string)
		num = ft_atoi(mini.iter->string);
	exit(num);
}

