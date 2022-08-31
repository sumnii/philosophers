#include "philosophers.h"

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int ft_atoi(char *str)
{
	int str_len;
	int num;
	int i;

	str_len = ft_strlen(str);
	num = 0;
	i = 0;
	while (str_len >= 1)
	{
		if (str[i] - '0' < 0 || 9 < str[i] - '0')
			return (-1);
		num = num * 10 + str[i] - '0';
		--str_len;
		++i;
	}
	return (num);
}