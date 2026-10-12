#include <stdio.h>

int stack[50];
int top = -1;

int main()
{
    char exp[50];
    int i, a, b;

    printf("Enter postfix: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            stack[++top] = exp[i] - '0';
        }
        else
        {
            b = stack[top--];
            a = stack[top--];

            if (exp[i] == '+')
                stack[++top] = a + b;
            else if (exp[i] == '-')
                stack[++top] = a - b;
            else if (exp[i] == '*')
                stack[++top] = a * b;
            else if (exp[i] == '/')
                stack[++top] = a / b;
        }
    }

    printf("Result :%d ", stack[top]);

    return 0;
}
