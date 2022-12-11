#include "../minishell.h"

int	where_is_start(int count_word, char *str) //kaçıncı kelimeye gitmek istediğimizi söyleyelim bizi oraya götürsün
{
	int	i;
	int	key;
	int	len;

	i = 0;
	key = 0;
	len = 0;
	if (!str)
		return (-1);
	while (str[i] != 0)
	{
		if (str[i] != 32 && key == 0)
		{
			key = 1;
			len++;
		}
		else if (key == 1 && str[i] == 32)
			key = 0;
		if (len == count_word)
			break;
		i++;
	}
	return (i);
}

int	where_is_end(int column, int start, t_shell *mini, int type)
{
	while (mini->parse[column][start] && mini->parse[column][start] != 32)
		start++;
	while (mini->parse[column][start] == type)
		start--;
	return (start);
}

char	*ft_add_quotes(int column, int start, t_shell *mini, int type)
{
	char	*str;
	int		i;
	int		end;

	while (mini->parse[column][start] == type)
		start++;
	end = where_is_end(column, start, mini, type);
	if (start >= end)
		return (NULL);
	str = malloc(sizeof(char) * (1 + end - start));
	i = 0;
	while (start < end)
	{
		while (mini->parse[column][start] == 34 || mini->parse[column][start] == 39)
			start++;
		str[i] = mini->parse[column][start];
		start++;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_add(int start, int column, t_shell *mini) //ekleme işlemi yapıyor verdiğimiz başlangıç adresinden ilerliyip bunu yapıyor.
{
	int	i;
	char *str;

	i = start;
	str = 0;
	if (start == -1)
		return (NULL);
	if (mini->parse[column][i] == 34 || mini->parse[column][i] == 39)
		return (ft_add_quotes(column, start, mini, mini->parse[column][i]));
	str = malloc(sizeof(char) *  (i - start + 1));
	if (!str)
		exit (-1);
	i = 0;
	while (mini->parse[column][start] && mini->parse[column][start] != ' ')
	{
		while (mini->parse[column][start] == 34 || mini->parse[column][start] == 39)
			start++;
		str[i] = mini->parse[column][start];
		start++;
		i++;
	}
	str[i] = 0;
	return (str);
}

char    *ft_add_string(t_shell *mini, int index, int start) //ahmet -d < "ceren" < noli naber | ceren < naptin
{
    char    **str;
    char    *result;
    int j;
    int i;

	if (mini->parse[index] == 0)
		return (0); // genel string NULL or ft_strdup("") indexede NULL biz genel stringe NULL atadık burada.
	str = ft_calloc(sizeof(char *), (len_word(mini->parse[index], 32) - start) + 1);
    j = 0;
    i = 0;
    while (start <= len_word(mini->parse[index], 32))
    {
        i = where_is_start(start, mini->parse[index]);
        str[j] = ft_add(i, index, mini);
        start++;
        j++;
    }
    str[j] = 0;
    result = ft_join_arg(str);
    return (result);
}

void	ft_add_struct(t_shell *mini)
{
	int	start;
	int i = 0;

	while (i < mini->pipe_count + 1)
	{
		mini->first_struct->command = where_is_command(i, mini, &start);
		mini->first_struct->string = ft_add_string(mini, i, start);
		mini->path = ft_mysplit(get_env("PATH", mini), ':', 1);
		i++;
	}
}
