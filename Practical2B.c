//call by value
#include <stdio.h>

void change(int x)
{
    x = 20;
    printf("Inside function: %d\n", x);
}

int main()
{
    int a = 10;

    printf("Before function call: %d\n", a);

    change(a);

    printf("After function call: %d\n", a);

    return 0;
}


//call by reference
#include <stdio.h>

void change(int *x)
{
    *x = 20;
    printf("Inside function: %d\n", *x);
}

int main()
{
    int a = 10;

    printf("Before function call: %d\n", a);

    change(&a);

    printf("After function call: %d\n", a);

    return 0;
}
