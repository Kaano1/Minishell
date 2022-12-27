#include "../minishell.h"
// sayı olmasa da normal terminal çıkış yapıyor
int	ft_exit(char **execute)
{
	int	num;

	num = 0;
	if (execute[1])
		num = ft_atoi(execute[1]);
	put_str("exit\n", 0);
	exit(num);
}
