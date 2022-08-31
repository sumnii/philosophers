#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	pid = fork();

	if (pid > 0)  // 부모 코드
	{
		printf("부모 프로세스 입니다.\n");
		printf("부모 pid : %d, 자식 pid : %d\n", getpid(), pid);
	}
	else if (pid == 0) // 자식 코드
	{
		printf("자식 프로세스 입니다.\n");
		printf("자식 pid : %d, 자식 없음 : %d\n", getpid(), pid);
	}
	else // fork 실패
		printf("fork fail!\n");

	return (0);
}
