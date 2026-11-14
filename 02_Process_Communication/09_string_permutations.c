#include <stdio.h>
#include <string.h>

void permute(char str[], int start, int end)
{
    if (start == end) {
        printf("%s\n", str);
        return;
    }

    for (int i = start; i <= end; i++) {
        char temp = str[start];
        str[start] = str[i];
        str[i] = temp;

        permute(str, start + 1, end);

        temp = str[start];
        str[start] = str[i];
        str[i] = temp;
    }
}

int main()
{
    char str[10];
    printf("Enter a string (max 9 characters): ");
    scanf("%9s", str);

    printf("Permutations:\n");
    permute(str, 0, (int)strlen(str) - 1);
    return 0;
}
