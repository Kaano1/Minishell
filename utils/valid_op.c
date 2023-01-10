#include "../minishell.h"

int	valid_op(char *str, int index)
{
	int	key;
	int	c;
	
	key = 0;
	if (index != 0)
		if (str[index - 1] == DOLLAR_C)
			key = 1;
	c = str[index + 1];
	return (((c >= 'a' && c <= 'z') || \
			(c >= 'A' && c <= 'Z') || \
			(c >= '0' && c <= '9') || \
			(c == '_') || (c == '?')) && (key == 0));
}
