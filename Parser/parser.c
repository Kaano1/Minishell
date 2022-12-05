#include "../minishell.h"

void	ft_create_struct(t_shell *mini)
{
	t_command	*first;
	int i;

	mini->first_struct = malloc(sizeof(t_command));
	first = mini->first_struct;
	i = 0;
	while (i < mini->pipe_count + 1)
	{
		mini->first_struct->next = malloc(sizeof(t_command));
		mini->first_struct->command = 0;
		mini->first_struct->string = 0;
		mini->first_struct->redirect = 0;
		mini->first_struct = mini->first_struct->next;
		i++;
	}
	mini->first_struct->next = 0;
	mini->first_struct = first;
}

size_t	len_word2(char **s)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = 0;
	while (s[++i])
		len += ft_strlen(s[i]);
	len += i;
	return (len);
}

char	*ft_join_arg(t_shell *mini) //double pointerli degiskenimizi single pointerli yapiyoruz.
{
	char	*str;
	int		i;
	int		j;
	int		save_i;

	str = malloc(sizeof(char) * len_word2(mini->parse)); //butun stringlerin uzunluguna gore alan ayiriyoruz
	j = 0;
	save_i = 0;
	while (mini->parse[j])
	{
		i = 0;
		if (mini->parse[j][i] == 0 && mini->parse[j + 1][i] != 0)
			j++;
		while (mini->parse[j][i])
		{
			str[save_i] = mini->parse[j][i];
			i++;
			save_i++;
		}
		if (mini->parse[j + 1] != 0)
        	str[save_i++] = 32;
		j++;
	}
    str[save_i] = 0;
    return (str);
}


void	ft_parse(t_shell *mini)
{
	int		i;

	i = 0;
	ft_create_struct(mini); //t_command structını pipe sayısı kadar üretiyoruz
	mini->iter = mini->first_struct; //başlangıç adresini elimizde tutuyoruz ne olur ne olmaz.
	mini->parse = ft_mysplit(mini->all_line, '|', 1);
	rediretion_cut_add(mini); //ahmet -d < "ceren" < noli | ceren < naptin
	mini->all_line = ft_join_arg(mini);
	mini->parse = ft_mysplit(mini->all_line, ' ', 1);
	mini->check_parser = ft_mysplit(mini->all_line, ' ', 1); //mini.parse '|' lardan arinmis ve "" lerden ayrilmis olucak bazi kontroller icin bunu yaptik
	mini->parse = find_dollar_and_change(mini);
	mini->all_line = ft_join_arg(mini);
	mini->parse = ft_mysplit(mini->all_line, '|', 1); //pipelardan bolme ve tirnak temizleme islemi yapiyoruz
	ft_add_struct(mini); //continue again
	exit (0);
	while (mini->parse[i])
	{
		printf("%s\n", mini->parse[i]);
		i++;
	}
}