#include "minishell.h"

int ft_space_check(int len, t_shell *mini) //all_linenı [0] indisini bosluklardan gectikten sonra ilk gordugu karakter yapıyor ve 
{										   //arkandanda ilk gordugu karakterin indis numarasını alıyor bu sekilde bas ve sondaki ilk karakterlere bakiyoruz.
	while (*mini->all_line == ' ')
		mini->all_line++;
	while (mini->all_line[len] == ' ')
		len--;
	mini->all_line[len + 1] = 0;
	return (len);
}

void 	ft_pipecheck(t_shell *mini)
{
	int len;
	int	i;
	char c;

	i = 0;
	mini->pipe_count = 0;
	len = ft_space_check(ft_strlen(mini->all_line) - 1, mini);
	if (mini->all_line[0] == '|' || mini->all_line[len] == '|') //basta veya sonra pipe varsa hata mesaji basip cikiyoruz.
		ft_error("WRONG!!!");
	while (mini->all_line[i]) //double pipe olma durumu soz konusu olursa double pipein arkasina NULL yapistiriyoruz
	{
		if (mini->all_line[i] != ' ')
			c = mini->all_line[i];
		i++;
		if (c == '|' && mini->all_line[i] == '|') 
		{
			while (len-- > i - 1)
				mini->all_line[len] = 0; //NULL yapistirma islemi oldugumuz yere kadar yapiyor.
		}
	}
}

void	ft_contqoute(t_shell *mini) //cift tirnak veya tek tıragin kapatilip kapatilmadigina bakiyoruz.
{
	int		i;
	int		once;
	int		twice;

	once = 0;
	twice = 0;
	i = 0;
	while (mini->all_line[i])
	{
		if (mini->all_line[i] == 39 && twice == 0)
			once++;
		else if (mini->all_line[i] == 34 && once == 0)
			twice++;
		i++;
		if (once == 2 || twice == 2)
		{
			once = 0;
			twice = 0;
		}
	}
	if (once % 2 != 0 || twice % 2 != 0)
		ft_error("Missing character!");
	add_history(mini->all_line);
}
