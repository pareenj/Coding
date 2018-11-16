#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 10;
    char c, d, e;
    c = 'h';
    d = 'E';
    e = 'X';
    printf("%c, %c, %2d, %c\n", c, d, a/2, e);
    char sum, diff, prod, div;
    sum = c+d;
    diff = c-d;
    prod = c*d;
    div = e/d;
    printf("%c, %c, %d, %d\n", sum, diff, prod, div);

    char echo;
    do
    {
        scanf("%c", &echo);
        printf("%c", echo);
    }
    while (echo != "\n");
}
