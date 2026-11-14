#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child before parent exits: PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(3);
        printf("Child after parent exits: PID = %d, PPID = %d\n", getpid(), getppid());
    }
    else if (pid > 0) {
        printf("Parent is exiting. PID = %d\n", getpid());
    }
    else {
        perror("fork");
        return 1;
    }
    return 0;
}
