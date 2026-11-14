#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int n, evenSum = 0, oddSum = 0;
    printf("Enter n: ");
    scanf("%d", &n);

    pid_t pid = fork();
    if (pid == 0) {
        for (int i = 1; i <= n; i++)
            if (i % 2 != 0) oddSum += i;
        printf("Child: sum of odd numbers = %d\n", oddSum);
    }
    else if (pid > 0) {
        for (int i = 1; i <= n; i++)
            if (i % 2 == 0) evenSum += i;
        printf("Parent: sum of even numbers = %d\n", evenSum);
        wait(NULL);
    }
    else {
        perror("fork");
        return 1;
    }
    return 0;
}
