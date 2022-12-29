#include "../minishell.h"

size_t	if_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
	{
		if (s[len] == DOUBLE_Q)
		{
			len++;
			while (s[len] != DOUBLE_Q && s[len] != 0)
				len++;
		}
		else if (s[len] == SIGNEL_Q)
		{
			len++;
			while (s[len] != SIGNEL_Q && s[len] != 0)
				len++;
		}
		else
			len++;
	}
	return (len);
}

size_t	len_word(char const *s, char c)
{
	size_t	len;
	int		key;

	len = 0;
	key = 0;
	while (*s != '\0')
	{
		if (*s == DOUBLE_Q || *s == SIGNEL_Q) //burdaki ibare "" or '' ifadelerde icinde bulunan kelimeleri saymasini istemedigimiz icin kullaniyoruz "ahmet mehmet ceren" bu tek kelime sayilsin diye.
			key += 1;
		if (*s != c && (s[1] == '\0' || s[1] == c) && key % 2 == 0)
			len++;
		s++;
	}
	return (len);
}

char	*mysplit_section(char ****res, char *s, int index, size_t *two_index)
{
	int	i;
	int	j;

	i = *two_index;
	j = 0;
	//burda tirnagi dahil edip etmiyecegimize karar veriyoruz
	res[0][0][index][i++] = s[j];
	if (s[j] == DOUBLE_Q)
	{
		while (s[++j] != DOUBLE_Q && s[j] != 0)
			res[0][0][index][i++] = s[j];
	}
	else if (s[j] == SIGNEL_Q)
	{
		while (s[++j] != SIGNEL_Q && s[j] != 0)
			res[0][0][index][i++] = s[j];
	}
	//tirnagi dahil ediyoruz ayni sekilde
	res[0][0][index][i++] = s[j++];
	*two_index = i;
	return ((char *)(s + j));
}

char	*create_split(char ***res, char *s, int c, int index)
{
	size_t	two_index;

	two_index = 0;
	while (*s != c && *s != '\0')
		if (*s == DOUBLE_Q || *s == SIGNEL_Q)
			s = mysplit_section(&res, s, index, &two_index); //atama islemleri gerceklesiyor
		else
			res[0][index][two_index++] = *s++;
	res[0][index][two_index] = '\0';
	return (s);
}

char	**ft_mysplit(char *s, char c) //normal split gibi tek degisiklik keylerini kullanarak bir butun seklinde "  naber  "
{												//gibi degerler alabiliyor olmamiz.
	char	**res;
	size_t	index;
	size_t	two_index;
	size_t	word_len;

	if (!s)
		return (0);
	word_len = len_word(s, c);
	res = (char **)malloc(sizeof(char *) * (word_len + 1));
	if (res == 0)
		return (0);
	index = 0;
	while (index < word_len)
	{
		while (*s == c && *s != '\0')
			s++; // ileriyoruz bir sonraki alinicak kelimeye kadar ama burdaki kod yanlizca ilerlemiyor tirnakta silebiliyor.
		res[index] = (char *)malloc(sizeof(char) * (if_word_len(s, c) + 1));
		s = create_split(&res, s, c, index);
		index++;
	}
	res[index] = 0;
	return (res);
}
