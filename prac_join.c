#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *t_function(void *param)
{
    printf("쓰레드 함수 실행\n");
    for (int i = 1; i <= 5; i++)
    {
        usleep(1000 * 1000);
        printf("쓰레드 함수 실행 중..(%d / 5)\n",i);
    }
        printf("쓰레드 함수 종료\n");
        return (void *)2147483647;  // result에 담길 값.
}

int main()
{
    pthread_t p_thread;
    int thr_id;
    int result;

    thr_id = pthread_create(&p_thread, NULL, t_function, NULL);
    if (thr_id < 0)
    {
        perror("thread create error : ");
        exit(0);
    }
    // 쓰레드 식별자 p_thread 가 종료되길 기다렸다가 
    // 종료후에 리턴값을 받아온다.
    pthread_join(p_thread, (void *)&result);
    printf("thread join 실행됨: %d\n", result);

    printf("main() 종료\n");

    return 0;
}

/* 결과값
 * 쓰레드 함수 실행
 * 쓰레드 함수 실행 중..(1 / 5)		// 1초마다 출력
 * 쓰레드 함수 실행 중..(2 / 5)
 * 쓰레드 함수 실행 중..(3 / 5)
 * 쓰레드 함수 실행 중..(4 / 5)
 * 쓰레드 함수 실행 중..(5 / 5)		// 여기부터 한번에
 * 쓰레드 함수 종료
 * thread join 실행됨: 2147483647
 * main() 종료
 */