#include "../minishell.h"

t_command	*init_struct(void)
{
	t_command	*command;

	command = ft_calloc(sizeof(t_command), 1);
	pipe(command->fd);
	command->pid = -1;
	command->command = NULL;
	command->redirect = NULL;
	command->next = NULL;
	command->prev = NULL;
	return (command);
}

void	ft_create_struct(void)
{
	int		i;

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

char	*ft_join_arg(char **mini)
{
	char	*str;
	int		i;
	int		j;
	int		save_i;

	str = malloc(sizeof(char) * len_word2(mini));
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

void	ft_parse(void)// echo kfdsajflkajdkfljalkfjdalkfjadlkjfd daksfjlkajfjdfalkdjflkadjflkajflkdajflkajf Ahmet
{
	ft_create_struct();
	mini.parse = ft_mysplit(mini.all_line, '|');
	rediretion_cut_add();
	free(mini.all_line);
	mini.all_line = ft_join_arg(mini.parse);
    free_array((mini.parse));
	mini.parse = ft_mysplit(mini.all_line, ' ');
	mini.parse = find_dollar_and_change();
    free(mini.all_line);
	mini.all_line = ft_join_arg(mini.parse);
	free_array((mini.parse));
	mini.parse = ft_mysplit(mini.all_line, '\t');
	mini.all_line = ft_join_arg(mini.parse);
	free(mini.parse);
	mini.parse = ft_mysplit(mini.all_line, '|');
	ft_add_struct();
	free_array(mini.parse);
	free(mini.all_line);
}
