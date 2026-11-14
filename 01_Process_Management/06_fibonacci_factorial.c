#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int n;
    long long fact = 1;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0 || n > 20) {
        printf("Enter a number between 0 and 20.\n");
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        int a = 0, b = 1;
        printf("Fibonacci series: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", a);
            int c = a + b;
            a = b;
            b = c;
        }
        printf("\n");
    }
    else if (pid > 0) {
        for (int i = 1; i <= n; i++)
            fact *= i;
        printf("Factorial = %lld\n", fact);
        wait(NULL);
    }
    else {
        perror("fork");
        return 1;
    }
    return 0;
}
