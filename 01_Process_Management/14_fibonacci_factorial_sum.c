#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    if (n < 0 || n > 20) {
        printf("Enter a value from 0 to 20.\n");
        return 1;
    }

    pid_t child = fork();
    if (child == 0) {
        int a = 0, b = 1;
        printf("First child - Fibonacci: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", a);
            int c = a + b;
            a = b;
            b = c;
        }
        printf("\n");

        pid_t grandchild = fork();
        if (grandchild == 0) {
            long long fact = 1;
            for (int i = 1; i <= n; i++)
                fact *= i;
            printf("Second child - Factorial = %lld\n", fact);
        }
        else if (grandchild > 0) {
            wait(NULL);
        }
        else {
            perror("fork");
            return 1;
        }
    }
    else if (child > 0) {
        int sum = n * (n + 1) / 2;
        printf("Parent - Sum of first %d natural numbers = %d\n", n, sum);
        wait(NULL);
    }
    else {
        perror("fork");
        return 1;
    }
    return 0;
}
