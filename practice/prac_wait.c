//
// Created by Sumin Song on 2022/08/23.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid;
	int status;

	pid = fork();

	if (pid > 0)
	{
		pid_t waitpid;
		printf("부모 PID : %d\n", getpid());
		waitpid = wait(&status); // 자식 프로세스의 상태를 받아올 때까지 wait!
		if (waitpid == -1) {
			printf("error\n");
		}
		else
		{
			printf("waitpid : %d\n", waitpid);
			if (WIFEXITED(status)) // 정상 종료되었다면 true
				printf("자식 프로세스 정상 종료\n");
			else if (WIFSIGNALED(status)) // 시그널에 의해 종료되었다면 true
				printf("자식 프로세스 비정상 종료: %d\n", WTERMSIG(status)); // 종료하도록 한 시그널 번호 반
		}
		printf("부모 프로세스 종료");
	}
	else if (pid == 0) {  // 자식 프로세스
		printf("자식 PID : %ld \n", (long)getpid());
		sleep(6);
	}
	else {  // fork 실패
		perror("fork Fail! \n");
		return (-1);
	}

	return (0);
}