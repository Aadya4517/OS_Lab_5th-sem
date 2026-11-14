#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0) {
        execlp("date", "date", (char *)NULL);
        perror("execlp");
        return 1;
    }
    else if (pid > 0) {
        wait(NULL);
        printf("Date command completed.\n");
    }
    else {
        perror("fork");
        return 1;
    }
    return 0;
}
