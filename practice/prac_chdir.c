//
// Created by Sumin Song on 2022/08/23.
//

#include <stdio.h>
#include <limits.h>
#include <unistd.h>	// chdir header

int main(void)
{
	char buffer[PATH_MAX] = { 0, };
//	char changeDir[PATH_MAX] = "/Users/42seoul/minishell/d";
	char *changeDir = "/Users/42seoul/minishell/d";

	printf("%s\n", changeDir);
	printf("%c\n", changeDir[0]);
	printf("%c\n", *changeDir);
	changeDir[0] = '?';
	printf("%s\n", changeDir);

	int result = chdir(changeDir);

	/*if (result == 0)
		printf("Success\n");
	else
		perror("Fail...\n"); */

	return 0;
}