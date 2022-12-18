#include "../minishell.h"

t_command	*init_struct(void)
{
	t_command	*command;

	command = ft_calloc(sizeof(t_command), 1);
	pipe(command->fd);
	command->pid = -1;
	command->command = ft_calloc(sizeof(char *), 1);
	command->string = ft_calloc(sizeof(char), 1);
	command->redirect = ft_calloc(sizeof(char *), 1);
	command->next = NULL;
	return (command);
}

void	ft_create_struct(void)
{
	int i;

	mini.iter = init_struct();
	mini.first_struct = mini.iter;
	i = 1;
	while (i < mini.pipe_count + 1)
	{
		pipe(mini.iter->fd);
		mini.iter->next = init_struct();
		mini.iter = mini.iter->next;
		i++;
	}
	mini.iter = mini.first_struct;
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


void	ft_parse(void)
{
	ft_create_struct(); //t_command structını pipe sayısı kadar üretiyoruz
	mini.parse = ft_mysplit(mini.all_line, '|', 1);
	rediretion_cut_add(); //ahmet -d < "ceren" < noli | ceren < naptin
	free(mini.all_line);
	mini.all_line = ft_join_arg(mini.parse);
	mini.parse = ft_mysplit(mini.all_line, ' ', 1);
	mini.check_parser = ft_mysplit(mini.all_line, ' ', 1); //mini.parse '|' lardan arinmis ve "" lerden ayrilmis olucak bazi kontroller icin bunu yaptik
	mini.parse = find_dollar_and_change();
	mini.all_line = ft_join_arg(mini.parse);
	mini.parse = ft_mysplit(mini.all_line, '|', 1); 
	//pipelardan bolme ve tirnak temizleme islemi yapiyoruz
	ft_add_struct(); //continue again
	
	
	
	/*while (mini.iter) //parser deneme
	{
		printf("command[0] = %s\n", mini.iter->command[0]);
		printf("flag = %s\n", mini.iter->command[1]);
		printf("string = %s\n", mini.iter->string);
		int	j;
		j = 0;
		while (mini.iter->redirect[j])
		{
			printf("redirect[%d] = %s\n", j, mini.iter->redirect[j]);
			j++;
		}
		i++;
		printf("\n\n\n");
		mini.iter = mini.iter->next;
	}*/
}