#include "../minishell.h"

void	get_all_inputs(t_process *process)
{
	int		i;
	char	**redirects;

	i = 0;
	redirects = mini.first_struct->redirect; 
	while (redirects[i])
	{
		if (is_operator(redirects[i]) == RED_INPUT)
			input(redirects[i + 1]);
		else if (is_operator(redirects[i]) == HERE_DOC)
			dup2(process->heredoc_fd[0], 0);
		i += 2;
	}
}

void	set_all_outputs(t_process *process)
{
	int		i;
	char	**redirects;

	i = 0;
	redirects = mini.first_struct->redirect;
	while (redirects[i])
	{
		if (is_operator(redirects[i]) == RED_OUTPUT)
			output(redirects[i + 1], REPLACE);
		else if (is_operator(redirects[i]) == RED_APPEND)
			output(redirects[i + 1], APPEND);
		i += 2;
	}
}

void	fill_all_heredoc(void)
{
	int			i;
	char		**redirects;
	t_command	*process;

	process = mini.first_struct;
	while (process)
	{
		i = 0;
		redirects = mini.first_struct->redirect;
		while (redirects[i] && !(mini.first_struct))
		{
			if (is_operator(redirects[i]) == HERE_DOC)
				heredoc(process->heredoc_fd, redirects[i + 1]);
			i += 2;
		}
		process = process->next;
	}
}




/*int redirect(char **str)
{
    int i = 0;
    char *file_name;

    while(str[i])
    {
        if(*str[i] == '>')
        {
            file_name = str[i + 1];
            input(file_name, '>');
        }
        else if(*str[i] == '>>')
        {
            file_name = str[i + 1];
            input(file_name, '>>');
        }
        else if(*str)
        i += 2;
    }
}

int main(int ac, char **av)
{
    char **str;
    str = (char **)malloc(sizeof(char *));
    char *str[0] = '>';
    char *str[1] = 'Ahmet';
    char *str[2] = '>>';
    char *str[3] = 'Mehmet';
    
    redirect(str);

}*/