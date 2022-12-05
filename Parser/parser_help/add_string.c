#include "../../minishell.h"

char	*ft_add_string(t_shell *mini, int index, int start) //ahmet -d < "ceren" < noli naber | ceren < naptin
{
	char	**str;
	char	*result;
	int	j;
	int	i;

	str = malloc(sizeof(char *) * (len_word(mini->parse[index], 32) - start) + 1);
	j = 0;
	i = 0;
	while (start <= len_word(mini->parse[index], 32))
	{
		i = where_is_start(start, mini->parse[index]);
		str[j] = ft_add(i, index, mini);
		start++;
		j++;
	}
	result = ft_join_arg(str);
	return (result);
}