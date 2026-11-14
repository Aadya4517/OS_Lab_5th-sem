#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {
        printf("This is child process. PID = %d, PPID = %d\n", getpid(), getppid());
    }
    else {
        printf("This is parent process. PID = %d, Child PID = %d\n", getpid(), pid);
        wait(NULL);
    }
    return 0;
}
