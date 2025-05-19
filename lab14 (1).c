#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    pid_t pid1, pid2, pid3;

    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        int sum_even = 0;
        for (int i = 2; i <= 1000; i += 2) {
            sum_even += i;
        }
        printf("Child 1: even sum is %d\n", sum_even);
        printf("DONE. MY PID IS %d. MY PARENT’S PID IS %d.\n", getpid(), getppid());
        exit(0);
    }

    pid2 = fork();
    if (pid2 < 0) {
        exit(1);
    }

    if (pid2 == 0) {
        int sum_odd = 0;
        for (int i = 1; i <= 1000; i += 2) {
            sum_odd += i;
        }
        printf("Child 2: even sum is %d\n", sum_odd);
        printf("DONE. MY PID IS %d. MY PARENT’S PID IS %d.\n", getpid(), getppid());
        exit(0);
    }

    pid3 = fork();
    if (pid3 < 0) {
        exit(1);
    }

    if (pid3 == 0) {
        printf("Child 3:Prime numbers are:\n");
        for (int i = 1; i <= 1000; ++i) {
            if (is_prime(i)) {
                printf("%d ", i);
            }
        }
        printf("\nDONE. MY PID IS %d. MY PARENT’S PID IS %d.\n", getpid(), getppid());
        exit(0);
    }

    wait(NULL);
    wait(NULL);
    wait(NULL);;
    printf("DONE. MY PID IS %d. MY PARENT’S PID IS %d.\n", getpid(), getppid());

    return 0;
}

