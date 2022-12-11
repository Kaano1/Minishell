#include "../minishell.h"

void	ft_create_struct(t_shell *mini)
{
	int i;

	mini->first_struct = malloc(sizeof(t_command));
	mini->iter = mini->first_struct;
	i = 0;
	while (i < mini->pipe_count + 1)
	{
		pipe(mini->first_struct->fd);
		mini->first_struct->pid = -1;
		mini->first_struct->next = malloc(sizeof(t_command));
		mini->first_struct->command = ft_calloc(sizeof(char *), 1);
		mini->first_struct->string = ft_calloc(sizeof(char *), 1);
		mini->first_struct->redirect = ft_calloc(sizeof(char *), 1);
		mini->first_struct = mini->first_struct->next;
		i++;
	}
	mini->first_struct->next = 0;
	mini->first_struct = mini->iter;
}

size_t	len_word2(char **s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		len += ft_strlen(s[i]);
		i++;
	}
	len += i;
	return (len);
}

char	*ft_join_arg(char **mini) //double pointerli degiskenimizi single pointerli yapiyoruz.
{
	char	*str;
	int		i;
	int		j;
	int		save_i;

	str = malloc(sizeof(char) * len_word2(mini)); //butun stringlerin uzunluguna gore alan ayiriyoruz
	j = 0;
	save_i = 0;
	while (mini[j])
	{
		i = 0;
		if (mini[j][i] == 0 && mini[j + 1][i] != 0)
			j++;
		while (mini[j][i])
		{
			str[save_i] = mini[j][i];
			i++;
			save_i++;
		}
		if (mini[j + 1] != 0)
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
	mini->parse = ft_mysplit(mini->all_line, '|', 1);
	rediretion_cut_add(mini); //ahmet -d < "ceren" < noli | ceren < naptin
	mini->all_line = ft_join_arg(mini->parse);
	mini->parse = ft_mysplit(mini->all_line, ' ', 1);
	mini->check_parser = ft_mysplit(mini->all_line, ' ', 1); //mini.parse '|' lardan arinmis ve "" lerden ayrilmis olucak bazi kontroller icin bunu yaptik
	mini->parse = find_dollar_and_change(mini);
	mini->all_line = ft_join_arg(mini->parse);
	mini->parse = ft_mysplit(mini->all_line, '|', 1); 
	//pipelardan bolme ve tirnak temizleme islemi yapiyoruz
	ft_add_struct(mini); //continue again
}