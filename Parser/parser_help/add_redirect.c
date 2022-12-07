#include "../../minishell.h"

int	if_while_quotes(char *str, int c)
{
	if (str[c] == 34)
	{
		c++;
			while (str[c] != 34 && str[c] != 0)
				c++;
	}
	else if (str[c] == 39)
	{
		c++;
		while (str[c] != 39 && str[c] != 0)
			c++;
	}
	if (str[c] == 0)
		c--;
	return (c);
}

char	**ft_redirection_add(t_shell *mini, int i) // redirectionları alıyoruz burada
{
	int	rc;
	int	r;
	int c;

	c = 0;
	r = 0;
	while (r <= ft_redirect_len(mini->parse[i]))
	{
		while (mini->parse[i][c] != '>' && mini->parse[i][c] != '<' && mini->parse[i][c] != 0)
		{
			c = if_while_quotes(mini->parse[i], c); //eğer bir tırnak varsa kapanana kadar c yi artırır
			c++;
		}
		if (mini->parse[i][c] == 0)
			break;
		mini->first_struct->redirect[r] = ft_redirect(mini, i, c); //hangi redirect işareti olduğunu ekliyoruz
		if (mini->first_struct->redirect[r][1] == '<' || mini->first_struct->redirect[r][1] == '>')
			c++;
		c++;
		r++;
		while (mini->parse[i][c] == ' ')
			c++;
		while (mini->parse[i][c] == 34 || mini->parse[i][c] == 39) //tırnakları geçiyoruz
			c++;
		mini->first_struct->redirect[r] = malloc(sizeof(char) * redirect_of_string_len(mini, i, c) + 1);
		rc = 0;
		while (mini->parse[i][c] != 0 && mini->parse[i][c] != 32 && mini->parse[i][c] != 34 && mini->parse[i][c] != 39)
		{
			mini->first_struct->redirect[r][rc] = mini->parse[i][c];
			c++;
			rc++;
		}
		while (mini->parse[i][c] == 34 || mini->parse[i][c] == 39) //sonda kalan tırnakları geçiyoruz.
			c++;
		mini->first_struct->redirect[r][rc] = 0;
		r++;
	}
	return (mini->first_struct->redirect);
}

char	*ft_redirection_clean(t_shell *mini, int i) //ahmet -d < "ceren"< noli | ceren < naptin bu şekilde olursa nasıl silebiliriz.
{
	int c;
	int	r;

	c = 0;
	r = 0;
	while (r <= ft_redirect_len(mini->parse[i]))
	{
		while (mini->parse[i][c] != '>' && mini->parse[i][c] != '<' && mini->parse[i][c] != 0)
		{
			c = if_while_quotes(mini->parse[i], c);
			c++;
		}
		if (mini->parse[i][c] == 0)
			break;
		mini->parse[i][c] = 32;
		c++;
		if (mini->parse[i][c] == '>' || mini->parse[i][c] == '<')
			mini->parse[i][c] = 32;
		while (mini->parse[i][c] == ' ')
			c++;
		while (mini->parse[i][c] != 0 && mini->parse[i][c] != 32 && mini->parse[i][c] != '<' && mini->parse[i][c] != '>')
		{
			mini->parse[i][c] = 32;
			c++;
		}
	}
	return (mini->parse[i]);
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
	return (result);
}

void	rediretion_cut_add(t_shell *mini)
{
	int	i;

	i = 0;
	while (i < mini->pipe_count + 1)
	{
		mini->first_struct->redirect = malloc(sizeof(char *) * ft_redirect_len(mini->parse[i]) + 1); // baktığımız 1. pipe stringinin içerisinde kaç adet redirect var.
		mini->first_struct->redirect = ft_redirection_add(mini, i); //redirectleri t_command structının içersindeki redirection değişkenimize tanımlıyoruz
		mini->parse[i] = ft_redirection_clean(mini, i); //tanımlanan redirectlerin yerine boşluk ataması yapıyoruz
		mini->parse[i] = pipe_add(mini->parse[i], mini->pipe_count, i); // eğer varsa pipe atıp devam ediyoruz.
		mini->first_struct = mini->first_struct->next; //ilerliyoruz.
		i++;
	}
	mini->first_struct = mini->iter;
}

//kafamdaki yapı
//bütün redirectionlar alınacak
//bütün redirectionların yerine boşluk ataması yapılacak

//boşluklardan arındırılıp baştakini command ve varsa flags olarak almayı planlıyoruz
//ardından bir şekilde stringleri almamız gerekiyor bunun için belki virgül temizleme işlemlerinden feragat edilebilinir veya geçici
//bir değişkene değerler atanabilinir.