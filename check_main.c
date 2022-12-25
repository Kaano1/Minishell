#include "minishell.h"

int pipe_space_check(int len, char *str) //all_linenı [0] indisini bosluklardan gectikten sonra ilk gordugu karakter yapıyor ve 
{										   //arkandanda ilk gordugu karakterin indis numarasını alıyor bu sekilde bas ve sondaki ilk karakterlere bakiyoruz.
	while (*str == ' ')
		str++;
	while (str[len] == ' ')
		len--;
	str = 0;
	return (len);
}

int 	ft_pipecheck(char *str)
{
	int len;
	int	i;
	char c;

	i = 0;
	mini.pipe_count = 0;
	len = pipe_space_check(ft_strlen(str) - 1, str);
	if (str[0] == '|' || str[len] == '|') //basta veya sonra pipe varsa hata mesaji basip cikiyoruz.
		ft_error("PIPE WRONG!!!");
	while (str[i]) //double pipe olma durumu soz konusu olursa double pipein arkasina NULL yapistiriyoruz
	{
		if (str[i] != ' ' && str[i] != '\t')
			c = str[i];
		i++;
		if (c == '|' && str[i] == '|') 
		{
			while (len-- > i - 1)
				str[len] = 0; //NULL yapistirma islemi oldugumuz yere kadar yapiyor.
		}
	}
	return (1);
}

int	ft_contqoute(char *str) //cift tirnak veya tek tıragin kapatilip kapatilmadigina bakiyoruz.
{
	int		i;
	int		once;
	int		twice;

	once = 0;
	twice = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 39 && twice == 0)
			once++;
		else if (str[i] == 34 && once == 0)
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
	return (1);
}
