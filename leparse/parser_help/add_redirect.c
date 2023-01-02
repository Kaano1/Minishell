#include "../../minishell.h"

int	if_while_quotes(char *str, int c)
{
	if (str[c] == DOUBLE_Q)
	{
		c++;
			while (str[c] != DOUBLE_Q && str[c] != 0)
				c++;
	}
	else if (str[c] == SIGNEL_Q)
	{
		c++;
		while (str[c] != SIGNEL_Q && str[c] != 0)
			c++;
	}
	if (str[c] == 0)
		c--;
	return (c);
}

void	ft_redirection_add(char **parse, int i) // redirectionları alıyoruz burada
{
	int	rc;
	int	r;
	int c;

	c = 0;
	r = 0;
	mini.iter->redirect = ft_calloc(sizeof(char *), (ft_redirect_len(parse[i]) * 2) + 1); 
	while (r <= ft_redirect_len(parse[i]))
	{
		while (parse[i][c] != '>' && parse[i][c] != '<' && parse[i][c] != 0)
		{
			c = if_while_quotes(parse[i], c); //eğer bir tırnak varsa kapanana kadar c yi artırır
			c++;
		}
		if (parse[i][c] == 0)
			break;
		mini.iter->redirect[r] = ft_redirect(parse, i, c); //hangi redirect işareti olduğunu ekliyoruz
		if (mini.iter->redirect[r][1] == '<' || mini.iter->redirect[r][1] == '>')
			c++;	
		c++;
		r++;
		while (parse[i][c] == ' ')
			c++;
		while (parse[i][c] == DOUBLE_Q || parse[i][c] == SIGNEL_Q) //tırnakları geçiyoruz.
			c++;
		mini.iter->redirect[r] = ft_calloc(sizeof(char), redirect_of_string_len(parse, i, c) + 1);
		rc = 0;
		while (parse[i][c] != 0 && parse[i][c] != SPACE && mini.parse[i][c] != TAB)
		{
			while (parse[i][c] && (parse[i][c] == DOUBLE_Q || parse[i][c] == SIGNEL_Q))
				c++;
			if (parse[i][c] == SPACE || parse[i][c] == TAB)
				break;
			mini.iter->redirect[r][rc] = parse[i][c];
			c++;
			rc++;
		}
		while (parse[i][c] == DOUBLE_Q || parse[i][c] == SIGNEL_Q) //sonda kalan tırnakları geçiyoruz.
			c++;
		mini.iter->redirect[r++][rc] = 0;
	}
	mini.iter->redirect[r] = 0;
}

void	ft_redirection_clean(int i) //ahmet -d < "ceren"< noli | ceren < naptin bu şekilde olursa nasıl silebiliriz.
{
	int c;
	int	r;

	c = 0;
	r = 0;
	while (r <= ft_redirect_len(mini.parse[i]))
	{
		while (mini.parse[i][c] != '>' && mini.parse[i][c] != '<' && mini.parse[i][c] != 0)
		{
			c = if_while_quotes(mini.parse[i], c);
			c++;
		}
		if (mini.parse[i][c] == 0)
			break;
		mini.parse[i][c] = SPACE;
		c++;
		if (mini.parse[i][c] == '>' || mini.parse[i][c] == '<')
			mini.parse[i][c] = SPACE;
		while (mini.parse[i][c] == ' ')
			c++;
		while ((mini.parse[i][c] != 0 && mini.parse[i][c] != TAB) \
			&&  (mini.parse[i][c] != SPACE && mini.parse[i][c] != '<' && mini.parse[i][c] != '>'))
		{
			mini.parse[i][c] = SPACE;
			c++;
		}
	}
}

char	*pipe_add(char *str, int count, int index)
{
	char	*result;
	int		i;

	i = 0;
	if (index + 1 > count)
		return (str);
	result = malloc(sizeof(char) * ft_strlen(str) + 2);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '|';
	result[i + 1] = 0;
	free(str);
	return (result);
}

void	rediretion_cut_add(void)
{
	int	i;

	i = 0;
	mini.iter = mini.first_struct;
	while (i < mini.pipe_count + 1)
	{
		mini.iter->redirect = ft_calloc(sizeof(char *), ft_redirect_len(mini.parse[i]) + 1); // baktığımız 1. pipe stringinin içerisinde kaç adet redirect var.
		ft_redirection_add(mini.parse, i); //redirectleri t_command structının içersindeki redirection değişkenimize tanımlıyoruz
		ft_redirection_clean(i); //tanımlanan redirectlerin yerine boşluk ataması yapıyoruz
		mini.parse[i] = pipe_add(mini.parse[i], mini.pipe_count, i); // eğer varsa pipe atıp devam ediyoruz.
		mini.iter = mini.iter->next; //ilerliyoruz.
		i++;
	}
	mini.iter = mini.first_struct;
}
