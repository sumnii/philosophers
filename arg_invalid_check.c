#include "philosophers.h"

int arg_count_check(int argc)
{
	if (argc != 5 && argc != 6)
	{
		printf("philo needs 4 or 5 arguments.\n");
		return (1);
	}
	return (0);
}

int arg_invalid_check(int argc, char *argv[])
{
	if (arg_count_check(argc))
		return (1);
	else
	{
		int i = 1;
		while (argv[i]) {
			printf("argv[%d] : %s\n", i, argv[i]);
			++i;
		}
	}
	return (0);
}

