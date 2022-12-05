#include "../minishell.h"

int	where_is_start(int count_word, char *str) //kaçıncı kelimeye gitmek istediğimizi söyleyelim bizi oraya götürsün
{
	int	i;
	int	key;
	int	len;

	i = 0;
	key = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != 32 && key == 0)
		{
			key = 1;
			len++;
		}
		else if (key == 1 && str[i] == 32)
			key = 0;
		if (len == count_word)
			break;
		i++;
	}
	return (i);
}

char	*ft_add(int row, int column, t_shell *mini) //ekleme işlemi yapıyor verdiğimiz başlangıç adresinden ilerliyip bunu yapıyor.
{
	int	i;
	char *str;

	i = row;
	str = 0;
	if (row == -1)
		return (NULL);
	while (mini->parse[column][i] != ' ')
		i++;
	str = malloc(sizeof(char) *  (i - row) + 1);
	if (!str)
		exit (-1);
	i = 0;
	while (mini->parse[column][row] != ' ')
	{
		str[i] = mini->parse[column][row];
		row++;
		i++;
	}
	str[i] = 0;
	return (str);
}

void	ft_add_struct(t_shell *mini)
{
	int	i;

	i = 0;
	i = where_is_start(1, mini->parse[i]);
	printf("%c", mini->parse[0][i]);
	while (i < mini->pipe_count + 1)
	{
		mini->first_struct->command = where_is_command(i, mini);// probably we must change this addition process
		//mini->first_struct->string = ft_add_string(mini, i);
		exit (0);
		printf("COMMAND: %s\n", mini->first_struct->command[0]);
		printf("RED: %s\n", mini->first_struct->redirect[0]);
		printf("STRING: %s\n", mini->first_struct->string);
		exit (0);
		if (mini->first_struct->redirect != 0)
		{
			//mini->first_struct->file_name = ft_add(where_is_start(0, i, mini), i, mini);
		}
		i++;
	}
    exit (0);
}
//where is command, where is flags, where is string and where is file_name yapalım
//ortak noktaları olursa onları bir fonksiyonda kullanalım
// ahmet
// -d
// mehmet
// |
// ceren
// -c
//

//redirectleri ekle
//redirectlerin oldugu bölüme boşluk ata
//ardından her zaman başındaki komuttur
//diger gelenlerin '-' isaretlerine bakılacak ve onlarda flags olarak adlandırılacak ve commanda eklenecek
//sona kalan kısım stringdir ağabey ondandır onları doğrudan alıp yazdıracağızda amma ve lakin 34 ve 39 silineceğinden ötürü düşünüyorum
//nasıl alabileceğimizi
//